// Copyright 2013, Gao Xinbo.  All rights reserved.
// Author: Gao Xinbo gaoxinbo1984@gmail.com

#include "util/mutex.h"
namespace gevent {
namespace util {

Mutex::Mutex(){
  pthread_mutex_init(&m_mutex, NULL);
}

Mutex::~Mutex(){
  pthread_mutex_destroy(&m_mutex);
}

void Mutex::Lock(){
  pthread_mutex_lock(&m_mutex);
  return;
}

void Mutex::Unlock(){
  pthread_mutex_unlock(&m_mutex);
  return;
}

}  // namespace util
}  // namespace gevent

