#include "net/tcpserver.h"

#include <unistd.h>
#include <iostream>

using namespace std;
using namespace gevent::net;
int main() {

  TcpServer server;
  bool ret = server.Listen(9999);
  if(!ret) {
    cout<<"listen 9999 error"<<endl;
  }

  while(1){
    sleep(1);
  }
  return 0;
}
