// Copyright 2013, Gao Xinbo.  All rights reserved.
// Author: Gao Xinbo gaoxinbo1984@gmail.com

#include "net/socket.h"
#include "net/constant.h"
#include <sys/socket.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>

using namespace std;
using namespace gevent::util;

namespace gevent {
namespace net {

Socket::Socket() {
  m_fd = -1;
}

Socket::Socket(const Socket &socket) {
  m_fd = socket.m_fd;
}

Socket::~Socket() {
  if (m_fd != -1)
    close(m_fd);
}

void Socket::operator=(const Socket &socket) {
  m_fd = socket.m_fd;
}

Status Socket::CreateServerSocket() {
  m_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (m_fd == -1)
    return Status::IOError("Create Socket error", strerror(errno));
  else
    return Status();
}

Status Socket::BindAndListen(const InetAddress &address) const {
  if (m_fd == -1)
    return Status::IllegalArgument("the fd to bind is -1","");
  InetAddress temp = address;
  sockaddr_in *addr = temp.GetSockAddr();
  int ret = bind(m_fd, reinterpret_cast<sockaddr *>(addr), sizeof(*addr));
  if (ret == -1)
    return Status::IOError("bind error", strerror(errno));

  ret = listen(m_fd, kListenBaklog);
  if (ret == -1)
    return Status::IOError("listen error", strerror(errno));

  return Status();
}

void Socket::SetBlocking(bool blocking) {
  if (m_fd == -1)
    return;
  int ret = fcntl(m_fd, F_GETFL);

  if (blocking)
    ret &= ~O_NONBLOCK;
  else
    ret |= O_NONBLOCK;  // non-blocking

  fcntl(m_fd, F_SETFL, ret);
}

void Socket::SetReuse(bool reuse) {
  int opt = reuse ? 1 : 0;
  setsockopt(m_fd, SOL_SOCKET, SO_REUSEADDR, (const void *)&opt, sizeof(opt));
}

Socket *Socket::Accept() {
  InetAddress address;
  Socket *result = NULL;

  socklen_t len = sizeof(*address.GetSockAddr());
  int client_fd = accept(m_fd, (sockaddr *)address.GetSockAddr(), &len);
  if(client_fd == -1){
    return result;
  }

  result = new Socket();
  result->SetFd(client_fd);
  return result;
}

InetAddress Socket::GetRemoteAddr() {
  InetAddress address;
  socklen_t len = sizeof(address.GetSockAddr());
  getsockname(m_fd, (sockaddr *)address.GetSockAddr(), &len);
  return address;
}

}  // namespace net
}  // namespace gevent

