set(net_src inetaddress.cc 
            socket.cc 
            eventhandler.cc
            accepter.cc
            )
add_library(libnet ${net_src})    
