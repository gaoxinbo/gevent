// Copyright 2013, Gao Xinbo.  All rights reserved.
// Author: Gao Xinbo gaoxinbo1984@gmail.com

#include "net/databuffer.h"
#include <arpa/inet.h>

using namespace std;

namespace gevent {
namespace net {

DataBuffer::DataBuffer() {
  m_buf = new char[1024];
  m_writable = m_buf;
  m_readble = m_buf;
}

DataBuffer::~DataBuffer() {
  delete m_buf;
}

void DataBuffer::AppendString(const char *p, int size) {
  memcpy(m_writable, p, size);
  m_writable+=size;
}

void DataBuffer::AppendInt8(int8_t i) {
  AppendString((char *)&i , sizeof(i));
}

void DataBuffer::AppendInt16(int16_t i) {
  int16_t t = htons(i);
  AppendString((char *)&t , sizeof(t));
}

void DataBuffer::AppendInt32(int32_t i) {
  int32_t t =  htonl(i);
  AppendString((char *)&t , sizeof(t));
}

int8_t DataBuffer::ReadInt8() {
  int8_t ret;
  memcpy(&ret, m_readble, sizeof(ret));
  m_readble += sizeof(ret);
  return ret;
}

int16_t DataBuffer::ReadInt16() {
  int16_t ret;
  memcpy(&ret, m_readble, sizeof(ret));
  m_readble += sizeof(ret);
  return ntohs(ret);
}

int32_t DataBuffer::ReadInt32() {
  int32_t ret;
  memcpy(&ret, m_readble, sizeof(ret));
  m_readble += sizeof(ret);
  return ntohl(ret);
}

}  // namespace net
}  // namespace gevent

