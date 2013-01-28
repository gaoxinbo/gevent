// File: tcpconnection.h
// Author: Gao Xinbo gaoxinbo1984@gmail.com
// Version: 1.0
// Date: 2013-01-22
// Copyright 2013, Gao Xinbo.  All rights reserved.

#ifndef _TCPCONNECTION_H_
#define _TCPCONNECTION_H_

#include "net/inetaddress.h"
#include "net/socket.h"

namespace gevent {
namespace net {

class TcpConnection {
  public:
    TcpConnection();
    ~TcpConnection();

    inline void SetSocket(Socket *socket) {
      m_socket = socket;
    }

    inline void SetLocalAddress(InetAddress address){
      m_local = address;
    }

    inline void SetPeerAddress(InetAddress address) {
      m_peer = address;
    }

    inline int GetSocketFd() {
      if(m_socket== NULL)
        return -1;
      return m_socket->GetFd();
    }

    inline void ShutDown(){
      if(m_socket == NULL)
        return;
      m_socket->ShutDown();
    }

    util::Status Connect(const char *p, unsigned short int);
  private:
    InetAddress m_peer;
    InetAddress m_local;
    Socket *m_socket;

    time_t m_start;
    time_t m_lastactive;
    time_t m_timeout;

    TcpConnection(const TcpConnection&);
    void operator=(const TcpConnection&);
};

}  // namespace net
}  // namespace gevent
#endif  // _TCPCONNECTION_H_

