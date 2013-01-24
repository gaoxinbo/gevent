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
namespace gevent {
namespace net {

class Accepter : public EventHandler{
  public:
    Accepter();
    virtual ~Accepter();

    virtual void OnRead();
    virtual void OnWrite();

    bool Listen(unsigned short port);

  private:
    InetAddress m_address;
    Socket m_socket;

    Accepter(const Accepter&);
    void operator=(const Accepter&);
};

}  // namespace net
}  // namespace gevent
#endif  // _ACCEPTER_H_

