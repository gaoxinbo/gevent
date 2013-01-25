// Copyright 2013, Gao Xinbo.  All rights reserved.
// Author: Gao Xinbo gaoxinbo1984@gmail.com

#include "net/tcpserver.h"

using namespace gevent::util;
namespace gevent {
namespace net {

TcpServer::TcpServer() {
}

TcpServer::~TcpServer() {
}

Status TcpServer::Listen(unsigned short port) {
  m_port = port;
  Status s = m_accepter.Listen(port);
  return s;
}

}  // namespace net
}  // namespace gevent

