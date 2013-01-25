// Copyright 2013, Gao Xinbo.  All rights reserved.
// Author: Gao Xinbo gaoxinbo1984@gmail.com

#include "net/accepter.h"
#include <iostream>

using namespace std;
using namespace gevent::util;

namespace gevent {
namespace net {

Accepter::Accepter() {
  m_server = NULL;
}

Accepter::~Accepter() {
}

void Accepter::OnRead(){
  Socket *socket;
  while((socket = m_socket.Accept()) != NULL){
    InetAddress addr = socket->GetRemoteAddr();
  }
}

void Accepter::OnWrite(){
  return;
}

Status Accepter::Listen(unsigned short port) {
  m_address.SetPort(port);
  Status s= m_socket.CreateServerSocket();
  if (!s.OK())
    return s;

  m_socket.SetBlocking(false);
  m_socket.SetReuse(true);

  s = m_socket.BindAndListen(m_address);
  return s;
}

}  // namespace net
}  // namespace gevent

