#include "net/tcpconnection.h"
#include <iostream>

using namespace std;
using namespace gevent::net;
using namespace gevent::util;

int main(){
  TcpConnection connection;
  Status s = connection.Connect("10.232.130.3",8888);
  if(!s.OK()) {
    cout<<s.ToString()<<endl;
    return 1;
  }
  return 0;
}

