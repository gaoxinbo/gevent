#include "net/tcpserver.h"

#include <unistd.h>
#include <iostream>

using namespace std;
using namespace gevent::net;
using namespace gevent::util;

int main(int argc, char **argv) {
  int port = 9999;
  if(argc >= 2)
    port = atoi(argv[1]);
  TcpServer server;
  Status s= server.Listen(port);
  if(!s.OK()) {
    cout<<s.ToString()<<endl;
    return 1;
  }

  server.Run();
  return 0;
}
