// File: eventlooper.h
// Author: Gao Xinbo gaoxinbo1984@gmail.com
// Version: 1.0
// Date: 2013-01-23
// Copyright 2013, Gao Xinbo.  All rights reserved.

#ifndef _EVENTLOOPER_H_
#define _EVENTLOOPER_H_

#include "net/eventhandler.h"
namespace gevent {
namespace net {

class EventLooper {
  public:
    EventLooper();
    ~EventLooper();

    bool init();
    bool SetEvent(EventHandler *handler, int fd, bool readable, bool writable);
    bool RemoveEvent(EventHandler *handler, int fd);

  private:
    int m_epoll_fd;

    EventLooper(const EventLooper&);
    void operator=(const EventLooper&);
};

}  // namespace net
}  // namespace gevent
#endif  // _EVENTLOOPER_H_

