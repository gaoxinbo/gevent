// Copyright 2013, Gao Xinbo.  All rights reserved.
// Author: Gao Xinbo gaoxinbo1984@gmail.com

#include "net/eventlooper.h"
#include "net/eventhandler.h"
#include "net/constant.h"

#include <errno.h>
#include <sys/epoll.h>
#include <unistd.h>

using namespace gevent::util;
namespace gevent {
namespace net {

EventLooper::EventLooper() {
  m_epoll_fd = -1;
}

EventLooper::~EventLooper() {
  if (m_epoll_fd != -1) 
    close(m_epoll_fd);
} 

Status EventLooper::init() {
  m_epoll_fd = epoll_create(kEpollSize);
  if(m_epoll_fd == -1)
    return Status::IOError("create epoll fd error", strerror(errno));
  return Status();
}

Status EventLooper::SetEvent(EventHandler *handler, int fd, bool readable, bool writable) {
  epoll_event ev;
  ev.data.ptr = handler;
  ev.events = 0;
  if(readable)
    ev.events |= EPOLLIN;
  if(writable)
    ev.events |= EPOLLOUT;

  int ret = epoll_ctl(m_epoll_fd, EPOLL_CTL_MOD, fd, &ev);
  if(ret == -1){
    if(errno == ENOENT){
      // if not exist, try to add it
      ret = epoll_ctl(m_epoll_fd, EPOLL_CTL_ADD, fd, &ev);
      if(ret == -1)
        return Status::IOError("add event error", strerror(errno));
    }
    else
      return Status::IOError("add event error", strerror(errno));
  }
  return Status();
}

Status EventLooper::RemoveEvent(EventHandler *handler, int fd) {
  epoll_event ev;
  ev.data.ptr = handler;
  ev.events = 0;
  int ret = epoll_ctl(m_epoll_fd, EPOLL_CTL_DEL, fd, &ev);
  if(ret == -1) 
    return Status::IOError("remove event error", strerror(errno));
  return Status();
}

void EventLooper::Run(){
  while(1){
    epoll_event ev[kEpollSize];
    int n = epoll_wait(m_epoll_fd, ev, kEpollSize,100);
    if(n == -1 && errno == EINTR)
      continue;
    // TODO handle error scenario
    for(int i = 0; i<n;i++){
      if(ev[i].events & EPOLLIN){
        EventHandler *handler = (EventHandler *)ev[i].data.ptr;
        handler->OnRead();
      } else if(ev[i].events & EPOLLOUT){
        EventHandler *handler = (EventHandler *)ev[i].data.ptr;
        handler->OnWrite();
      }
    }

  }
}

}  // namespace net
}  // namespace gevent

