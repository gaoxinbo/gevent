// Copyright 2013, Gao Xinbo.  All rights reserved.
// Author: Gao Xinbo gaoxinbo1984@gmail.com

#include "net/eventlooper.h"
#include <sys/epoll.h>
#include <unistd.h>
namespace gevent {
namespace net {

EventLooper::EventLooper() {
  m_epoll_fd = -1;
}

EventLooper::~EventLooper() {
  if (m_epoll_fd != -1) 
    close(m_epoll_fd);
} 

bool EventLooper::init() {
  m_epoll_fd = epoll_create(256);
  return true;
}

bool EventLooper::SetEvent(EventHandler *handler, int fd, bool readable, bool writable) {
  epoll_event ev;
  ev.data.ptr = handler;
  ev.events = 0;
  if(readable)
    ev.events |= EPOLLIN;
  if(writable)
    ev.events |= EPOLLOUT;

  int ret = epoll_ctl(m_epoll_fd, EPOLL_CTL_MOD, fd, &ev);
  if(ret != 0)
    return false;
  return true;
}

bool EventLooper::RemoveEvent(EventHandler *handler, int fd) {
  epoll_event ev;
  ev.data.ptr = handler;
  ev.events = 0;
  int ret = epoll_ctl(m_epoll_fd, EPOLL_CTL_DEL, fd, &ev);
  if(ret != 0) 
    return false;
  return true;
}

}  // namespace net
}  // namespace gevent

