// File: Socket.h
// Author: Gao Xinbo gaoxinbo1984@gmail.com
// Version: 1.0
// Date: 2013-01-21
// Copyright 2013, Gao Xinbo.  All rights reserved.

#ifndef _SOCKET_H_
#define _SOCKET_H_

#include "net/inetaddress.h"
namespace network {
namespace net {

class Socket {
  public:
    Socket();
    ~Socket();

    bool CreateSocket();
    bool BindAndListen(const InetAddress &address) const;

    void SetBlocking(bool blocking);
    void SetReuse(bool reuse);

  private:
    int m_fd;  // socket fd

    Socket(const Socket&);
    void operator=(const Socket&);
};

}  // namespace net
}  // namespace network
#endif  // _SOCKET_H_

