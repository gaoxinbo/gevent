// File: eventhanlder.h
// Author: Gao Xinbo gaoxinbo1984@gmail.com
// Version: 1.0
// Date: 2013-01-22
// Copyright 2013, Gao Xinbo.  All rights reserved.

#ifndef _EVENTHANLDER_H_
#define _EVENTHANLDER_H_
namespace network {
namespace net {

class EventHandler {
  public:
    EventHandler();
    virtual ~EventHandler();

    virtual void OnRead() = 0;
    virtual void OnConnect() = 0;
    virtual void OnWrite() = 0;
    virtual void OnClose() = 0;

  private:
    EventHandler(const EventHandler&);
    void operator=(const EventHandler&);
};

}  // namespace net
}  // namespace network
#endif  // _EVENTHANLDER_H_

