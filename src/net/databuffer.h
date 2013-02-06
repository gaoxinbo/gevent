// File: databuffer.h
// Author: Gao Xinbo gaoxinbo1984@gmail.com
// Version: 1.0
// Date: 2013-01-29
// Copyright 2013, Gao Xinbo.  All rights reserved.

#ifndef _DATABUFFER_H_
#define _DATABUFFER_H_

#include "sys/types.h"
#include <string>
#include <vector>

namespace gevent {
namespace net {

class DataBuffer {
  public:
    DataBuffer();
    ~DataBuffer();

    void AppendString(const std::string &str);
    void AppendInt8(int8_t i);
    void AppendInt16(int16_t i);
    void AppendInt32(int32_t i);

    int8_t ReadInt8();
    int16_t ReadInt16();
    int32_t ReadInt32();
    std::string ReadString();

    int8_t PeekInt8();
    int16_t PeekInt16();
    int32_t PeekInt32();

    void MoveForward(int step);

    inline int Writable() {
      return m_buf.size() - m_writable;
    }
    inline int Readble() {
      return m_writable - m_readble;
    }
    inline int Hole() {
      return m_readble;
    }

  private:
    std::vector<char> m_buf;
    int m_writable;
    int m_readble;

    void AppendString(const char *p, int size);
    const char * Peek() const {
      return &(*m_buf.begin()) + m_readble;
    }
    void MakeSpace(int n);
    DataBuffer(const DataBuffer&);
    void operator=(const DataBuffer&);
};

}  // namespace net
}  // namespace gevent
#endif  // _DATABUFFER_H_

