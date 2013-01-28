// File: scopeguard.h
// Author: Gao Xinbo gaoxinbo1984@gmail.com
// Version: 1.0
// Date: 2013-01-28
// Copyright 2013, Gao Xinbo.  All rights reserved.

#ifndef _SCOPEGUARD_H_
#define _SCOPEGUARD_H_

#include "util/mutex.h"

namespace gevent {
namespace util {

class ScopeGuard {
  public:
    ScopeGuard(Mutex *mutex);
    ~ScopeGuard();

  private:
    Mutex *m_mutex;

    ScopeGuard(const ScopeGuard&);
    void operator=(const ScopeGuard&);
};

}  // namespace util
}  // namespace gevent
#endif  // _SCOPEGUARD_H_

