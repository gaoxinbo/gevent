// File: Socket.h
// Author: Gao Xinbo gaoxinbo1984@gmail.com
// Version: 1.0
// Date: 2013-01-21
// Copyright 2013, Gao Xinbo.  All rights reserved.

#ifndef _SOCKET_H_
#define _SOCKET_H_

#include "net/inetaddress.h"
#include "util/status.h"

namespace gevent {
namespace net {

class Socket {
  public:
    Socket();
    Socket(const Socket &);
    ~Socket();
    void operator=(const Socket&);

    util::Status CreateServerSocket();
    util::Status BindAndListen(const InetAddress &address) const;
    util::Status Connect(const char *ip, unsigned short port);

    void SetBlocking(bool blocking);
    void SetReuse(bool reuse);
    Socket *Accept();
    InetAddress GetRemoteAddr();

    inline int GetFd(){
      return m_fd;
    }

    inline void SetFd(int fd){
      m_fd = fd;
    }

  private:
    int m_fd;  // socket fd

};

}  // namespace net
}  // namespace gevent
#endif  // _SOCKET_H_

