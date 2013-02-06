// Copyright 2013, Gao Xinbo.  All rights reserved.
// Author: Gao Xinbo gaoxinbo1984@gmail.com

#include "net/databuffer.h"
#include "net/constant.h"
#include <assert.h>
#include <arpa/inet.h>
#include <algorithm>

using namespace std;

namespace gevent {
namespace net {

DataBuffer::DataBuffer() : m_buf(kDatabufLen){
  m_writable = 0;
  m_readble = 0;
}

DataBuffer::~DataBuffer() {
}

void DataBuffer::AppendString(const string &str) {
  AppendInt32(str.length());
  AppendString(str.data(),str.length());
}
void DataBuffer::AppendString(const char *p, int size) {
  MakeSpace(size);
  copy(p, p+size, &(*m_buf.begin())+m_writable);
  m_writable+=size;
}

void DataBuffer::AppendInt8(int8_t i) {
  MakeSpace(sizeof(i));
  AppendString((char *)&i , sizeof(i));
}

void DataBuffer::AppendInt16(int16_t i) {
  MakeSpace(sizeof(i));
  int16_t t = htons(i);
  AppendString((char *)&t , sizeof(t));
}

void DataBuffer::AppendInt32(int32_t i) {
  MakeSpace(sizeof(i));
  int32_t t =  htonl(i);
  AppendString((char *)&t , sizeof(t));
}

int8_t DataBuffer::ReadInt8() {
  int8_t ret = PeekInt8();
  MoveForward(sizeof(ret));
  return ret;
}

int16_t DataBuffer::ReadInt16() {
  int16_t ret = PeekInt16();
  MoveForward(sizeof(ret));
  return ret;
}

int32_t DataBuffer::ReadInt32() {
  int32_t ret = PeekInt32();
  MoveForward(sizeof(ret));
  return ret;
}

string DataBuffer::ReadString(){
  int32_t length = 0;
  assert(Readble() >= 4);
  length = ReadInt32();
  string ret = "";
  ret.resize(length);
  memcpy(&ret[0], Peek(), length);
  MoveForward(length);
  return ret;
}

int8_t DataBuffer::PeekInt8() {
  int8_t ret = 0;
  assert(Readble() >= 1);
  memcpy(&ret, Peek(), sizeof(ret));
  return ret;
}

int16_t DataBuffer::PeekInt16() {
  int16_t ret = 0;
  assert(Readble() >= 2);
  memcpy(&ret, Peek(), sizeof(ret));
  return ntohs(ret);
}

int32_t DataBuffer::PeekInt32() {
  int32_t ret = 0;
  assert(Readble() >= 4);
  memcpy(&ret, Peek(), sizeof(ret));
  return ntohl(ret);
}


void DataBuffer::MoveForward(int step) {
  m_readble += step;
}

void DataBuffer::MakeSpace(int n) {
  if(Writable() < n){
    if(Hole() >= kDatabufLen){
      copy(m_buf.begin()+m_readble, m_buf.begin() + m_writable, m_buf.begin());
      m_readble = 0;
      m_writable = Writable();
      if(Writable() >= n)
        return;
    }
    int space = kDatabufLen;
    while(space < n){
      space *= 2;
    }
    m_buf.resize(space);
  }
}

}  // namespace net
}  // namespace gevent

