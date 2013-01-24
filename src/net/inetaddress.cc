// Copyright 2013, Gao Xinbo.  All rights reserved.
// Author: Gao Xinbo gaoxinbo1984@gmail.com

#include "net/inetaddress.h"

#include <string.h>

namespace gevent {
namespace net {

InetAddress::InetAddress() {
    memset(&m_addr, 0, sizeof(m_addr));
    m_addr.sin_family = AF_INET;
    m_addr.sin_addr.s_addr = INADDR_ANY;
}

InetAddress::InetAddress(const InetAddress& addr) {
    m_addr = addr.m_addr;
}

InetAddress::~InetAddress() {
}

}  // namespace net
}  // namespace gevent

