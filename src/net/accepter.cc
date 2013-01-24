// Copyright 2013, Gao Xinbo.  All rights reserved.
// Author: Gao Xinbo gaoxinbo1984@gmail.com

#include "net/accepter.h"
namespace gevent {
namespace net {

Accepter::Accepter() {
}

Accepter::~Accepter() {
}

void Accepter::OnRead(){
}

void Accepter::OnWrite(){
  return;
}

bool Accepter::Listen(unsigned short port) {
  m_address.SetPort(port);
  bool ret = m_socket.CreateServerSocket();
  if (!ret)
    return false;

  m_socket.SetBlocking(false);
  m_socket.SetReuse(true);

  ret = m_socket.BindAndListen(m_address);
  if (!ret)
    return false;
  return true;
}

}  // namespace net
}  // namespace gevent

