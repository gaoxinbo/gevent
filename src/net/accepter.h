// File: accepter.h
// Author: Gao Xinbo gaoxinbo1984@gmail.com
// Version: 1.0
// Date: 2013-01-22
// Copyright 2013, Gao Xinbo.  All rights reserved.

#ifndef _ACCEPTER_H_
#define _ACCEPTER_H_

#include "net/inetaddress.h"
#include "net/socket.h"
namespace network {
namespace net {

class Accepter {
  public:
    Accepter();
    ~Accepter();

    bool Listen(unsigned short port);

  private:
    InetAddress m_address;
    Socket m_socket;

    Accepter(const Accepter&);
    void operator=(const Accepter&);
};

}  // namespace net
}  // namespace network
#endif  // _ACCEPTER_H_

