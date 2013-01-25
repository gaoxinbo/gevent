// File: accepter.h
// Author: Gao Xinbo gaoxinbo1984@gmail.com
// Version: 1.0
// Date: 2013-01-22
// Copyright 2013, Gao Xinbo.  All rights reserved.

#ifndef _ACCEPTER_H_
#define _ACCEPTER_H_

#include "net/eventhandler.h"
#include "net/inetaddress.h"
#include "net/socket.h"
#include "util/status.h"

namespace gevent {
namespace net {

class TcpServer;

class Accepter : public EventHandler{
  public:
    Accepter();
    virtual ~Accepter();

    virtual void OnRead();
    virtual void OnWrite();

    util::Status Listen(unsigned short port);
    inline int GetFd(){
      return m_socket.GetFd();
    }

    inline void SetTcpServer(TcpServer *server){
      m_server = server;
    }

  private:
    InetAddress m_address;
    Socket m_socket;
    TcpServer *m_server;

    Accepter(const Accepter&);
    void operator=(const Accepter&);
};

}  // namespace net
}  // namespace gevent
#endif  // _ACCEPTER_H_

