// Copyright 2013, Gao Xinbo.  All rights reserved.
// Author: Gao Xinbo gaoxinbo1984@gmail.com

#include "net/tcpserver.h"
namespace gevent {
namespace net {

TcpServer::TcpServer() {
}

TcpServer::~TcpServer() {
}

bool TcpServer::Listen(unsigned short port) {
  m_port = port;
  return m_accepter.Listen(port);
}

}  // namespace net
}  // namespace gevent

