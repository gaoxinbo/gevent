// File: status.h
// Author: Gao Xinbo gaoxinbo1984@gmail.com
// Version: 1.0
// Date: 2013-01-24
// Copyright 2013, Gao Xinbo.  All rights reserved.

#ifndef _STATUS_H_
#define _STATUS_H_

#include <string>

namespace gevent {
namespace util {

class Status {
  public:
    enum StatusCode{
      kOK,
      kIOError,
      kIllegalArgument,
      kStatusLength,
    };

    Status();
    Status(StatusCode code, std::string msg, std::string stderror);
    Status(const Status&);
    ~Status();

    std::string ToString();
    inline bool OK(){
      return (m_status == kOK);
    }
    inline StatusCode GetStatusCode() {
      return m_status;
    }

    static Status IOError(std::string msg, std::string stderror) { 
      return Status(kIOError, msg, stderror);
    }
    
    static Status IllegalArgument(std::string msg, std::string stderror) { 
      return Status(kIllegalArgument, msg, stderror);
    }

  private:
    StatusCode m_status;
    std::string m_msg;
    std::string m_stderr;

    void operator=(const Status&);
};

}  // namespace util
}  // namespace gevent
#endif  // _STATUS_H_

