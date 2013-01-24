// File: TcpServer.h
// Author: Gao Xinbo gaoxinbo1984@gmail.com
// Version: 1.0
// Date: 2013-01-23
// Copyright 2013, Gao Xinbo.  All rights reserved.

#ifndef _TCPSERVER_H_
#define _TCPSERVER_H_

#include "net/accepter.h"

namespace gevent {
namespace net {

class TcpServer {
  public:
    TcpServer();
    ~TcpServer();

    bool Listen(unsigned short port);

  private:
    unsigned int m_port;
    Accepter m_accepter; 
    TcpServer(const TcpServer&);
    void operator=(const TcpServer&);
};

}  // namespace net
}  // namespace gevent
#endif  // _TCPSERVER_H_

