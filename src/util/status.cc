// Copyright 2013, Gao Xinbo.  All rights reserved.
// Author: Gao Xinbo gaoxinbo1984@gmail.com

#include "status.h"
#include <string>

using namespace std;

namespace gevent {
namespace util {

Status::Status(){
  m_status = kOK;
}

Status::Status(StatusCode code, string msg, string stderror){
  m_status = code;
  m_msg = msg;
  m_stderr = stderror;
}

Status::Status(const Status &status){
  m_status = status.m_status;
  m_msg = status.m_msg;
  m_stderr = status.m_stderr;
}

Status::~Status(){
}

string Status::ToString(){
  string result;
  static char * status_format[kStatusLength] = {
    "OK",
    "IOError",
    "IllegalArgument"
  };

  result = status_format[m_status];
  if(m_msg.size()>0)
    result += " " + m_msg;
  if(m_stderr.size()>0)
    result += " :" + m_stderr;
  
  return result;
}

}  // namespace util
}  // namespace gevent

