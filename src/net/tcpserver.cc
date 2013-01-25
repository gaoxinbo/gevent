// Copyright 2013, Gao Xinbo.  All rights reserved.
// Author: Gao Xinbo gaoxinbo1984@gmail.com

#include "net/tcpserver.h"
#include <iostream>
using namespace std;
using namespace gevent::util;
namespace gevent {
namespace net {

TcpServer::TcpServer() {
}

TcpServer::~TcpServer() {
}

Status TcpServer::Listen(unsigned short port) {
  m_port = port;
  Status s = m_looper.init();
  if(!s.OK())
    return s;
  s = m_accepter.Listen(port);
  if(!s.OK())
    return s;

  s = m_looper.SetEvent(&m_accepter, m_accepter.GetFd(), true /* readable */, false /* writable */); 
  return s;
}

void TcpServer::Run() {
  m_looper.Run();
}
}  // namespace net
}  // namespace gevent

