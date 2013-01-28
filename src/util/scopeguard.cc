// Copyright 2013, Gao Xinbo.  All rights reserved.
// Author: Gao Xinbo gaoxinbo1984@gmail.com

#include "util/scopeguard.h"

namespace gevent {
namespace util {

ScopeGuard::ScopeGuard(Mutex *mutex):m_mutex(mutex){
  if(m_mutex != NULL)
    m_mutex->Lock();
}

ScopeGuard::~ScopeGuard(){
  if(m_mutex != NULL)
    m_mutex->Unlock();
}

}  // namespace util
}  // namespace gevent

