// File: tcpconnection.h
// Author: Gao Xinbo gaoxinbo1984@gmail.com
// Version: 1.0
// Date: 2013-01-22
// Copyright 2013, Gao Xinbo.  All rights reserved.

#ifndef _TCPCONNECTION_H_
#define _TCPCONNECTION_H_
namespace gevent {
namespace net {

class TcpConnection {
  public:
    TcpConnection();
    ~TcpConnection();

  private:
    TcpConnection(const TcpConnection&);
    void operator=(const TcpConnection&);
};

}  // namespace net
}  // namespace gevent
#endif  // _TCPCONNECTION_H_

