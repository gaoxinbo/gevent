// File: TcpServer.h
// Author: Gao Xinbo gaoxinbo1984@gmail.com
// Version: 1.0
// Date: 2013-01-23
// Copyright 2013, Gao Xinbo.  All rights reserved.

#ifndef _TCPSERVER_H_
#define _TCPSERVER_H_

#include "net/accepter.h"
#include "net/eventlooper.h"
#include "util/status.h"

namespace gevent {
namespace net {

class TcpServer {
  public:
    TcpServer();
    ~TcpServer();

    util::Status Listen(unsigned short port);
    void Run();

  private:
    unsigned int m_port;
    Accepter m_accepter; 
    EventLooper m_looper;

    TcpServer(const TcpServer&);
    void operator=(const TcpServer&);
};

}  // namespace net
}  // namespace gevent
#endif  // _TCPSERVER_H_

