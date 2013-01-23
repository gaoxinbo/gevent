// File: InetAddress.h
// Author: Gao Xinbo gaoxinbo1984@gmail.com
// Version: 1.0
// Date: 2013-01-21
// Copyright 2013, Gao Xinbo.  All rights reserved.

#ifndef _INETADDRESS_H_
#define _INETADDRESS_H_

#include "netinet/in.h"

namespace network {
namespace net {

class InetAddress {
  public:
    InetAddress();
    InetAddress(const InetAddress& addr);
    ~InetAddress();

    inline void SetPort(unsigned short port) {
        m_addr.sin_port = htons(port);
    }

    // return pointer so Listener can assign its value directly.
    inline sockaddr_in* GetSockAddr() {
        return &m_addr;
    }

  private:
    sockaddr_in m_addr;

    void operator=(const InetAddress&);
};

}  // namespace net
}  // namespace network
#endif  // _INETADDRESS_H_

