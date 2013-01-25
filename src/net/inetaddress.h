// File: InetAddress.h
// Author: Gao Xinbo gaoxinbo1984@gmail.com
// Version: 1.0
// Date: 2013-01-21
// Copyright 2013, Gao Xinbo.  All rights reserved.

#ifndef _INETADDRESS_H_
#define _INETADDRESS_H_

#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>

namespace gevent {
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

    inline void setSockAddr(const sockaddr_in &addr) {
      m_addr = addr;
    }

    std::string ToString(){
      char buf[64];
      inet_ntop(AF_INET, &m_addr.sin_addr, buf, 64);
      std::string result;
      result = buf;
      return result;
    }

  private:
    sockaddr_in m_addr;

    void operator=(const InetAddress&);
};

}  // namespace net
}  // namespace gevent
#endif  // _INETADDRESS_H_

