// File: databuffer.h
// Author: Gao Xinbo gaoxinbo1984@gmail.com
// Version: 1.0
// Date: 2013-01-29
// Copyright 2013, Gao Xinbo.  All rights reserved.

#ifndef _DATABUFFER_H_
#define _DATABUFFER_H_

#include "sys/types.h"
#include <string>

namespace gevent {
namespace net {

class DataBuffer {
  public:
    DataBuffer();
    ~DataBuffer();

    void AppendString(std::string str);
    void AppendInt8(int8_t i);
    void AppendInt16(int16_t i);
    void AppendInt32(int32_t i);

    int8_t ReadInt8();
    int16_t ReadInt16();
    int32_t ReadInt32();
    std::string ReadString();

  private:
    char *m_buf;
    char *m_writable; 
    char *m_readble; 

    void AppendString(const char *p, int size);
    DataBuffer(const DataBuffer&);
    void operator=(const DataBuffer&);
};

}  // namespace net
}  // namespace gevent
#endif  // _DATABUFFER_H_

