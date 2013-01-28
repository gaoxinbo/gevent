// File: mutex.h
// Author: Gao Xinbo gaoxinbo1984@gmail.com
// Version: 1.0
// Date: 2013-01-28
// Copyright 2013, Gao Xinbo.  All rights reserved.

#ifndef _MUTEX_H_
#define _MUTEX_H_

#include "pthread.h"
namespace gevent {
namespace util {

class Mutex {
  public:
    Mutex();
    ~Mutex();

    void Lock();
    void Unlock();

  private:
    pthread_mutex_t m_mutex;

    Mutex(const Mutex&);
    void operator=(const Mutex&);
};

}  // namespace util
}  // namespace gevent
#endif  // _MUTEX_H_

