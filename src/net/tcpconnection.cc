// Copyright 2013, Gao Xinbo.  All rights reserved.
// Author: Gao Xinbo gaoxinbo1984@gmail.com

#include "net/tcpconnection.h"
using namespace gevent::util;
namespace gevent {
namespace net {

TcpConnection::TcpConnection(){
  m_socket = NULL;
}

TcpConnection::~TcpConnection(){
  delete(m_socket);
  m_socket = NULL;
}

Status TcpConnection::Connect(const char *ip, unsigned short port){
  if(m_socket != NULL){
    delete(m_socket);
    m_socket = NULL;
  }

  m_socket = new Socket();
  Status s = m_socket->CreateServerSocket();
  if(!s.OK()) 
    return s;

  s = m_socket->Connect(ip, port);
  if(!s.OK())
    return s;
  m_peer = m_socket->GetRemoteAddr();
  return s;
}

}  // namespace net
}  // namespace gevent

