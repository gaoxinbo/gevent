// File: eventlooper.h
// Author: Gao Xinbo gaoxinbo1984@gmail.com
// Version: 1.0
// Date: 2013-01-23
// Copyright 2013, Gao Xinbo.  All rights reserved.

#ifndef _EVENTLOOPER_H_
#define _EVENTLOOPER_H_

#include "net/eventhandler.h"
#include "util/status.h"
namespace gevent {
namespace net {

class EventLooper {
  public:
    EventLooper();
    ~EventLooper();

    util::Status init();
    util::Status SetEvent(EventHandler *handler, int fd, bool readable, bool writable);
    util::Status RemoveEvent(EventHandler *handler, int fd);
    void Run();

  private:
    int m_epoll_fd;

    EventLooper(const EventLooper&);
    void operator=(const EventLooper&);
};

}  // namespace net
}  // namespace gevent
#endif  // _EVENTLOOPER_H_

