LIBRARY=libgevent.a
PROGRAMS=listen_server
TESTS=

all:${LIBRARY} ${PROGRAMS} 

${shell ./build_config.sh}
include build_config.mk
#LIBRARY_SOURCE=src/net/socket.cc \
               src/net/inetaddress.cc \
               src/net/eventhandler.cc \
               src/net/accepter.cc \
               src/net/tcpserver.cc \
               src/net/eventlooper.cc

LISTEN_SERVER_SRC=src/example/listen_server.cc               
LISTEN_SERVER_OBJ= ${LISTEN_SERVER_SRC:.cc=.o}              

OBJ=${SOURCE:.cc=.o}

CXX_FLAGS=-g -O2 -Wall -Werror -Isrc
LD_FLAGS=-g

.cc.o:
	g++ -c ${CXX_FLAGS} $< -o $@

listen_server:${LISTEN_SERVER_OBJ} ${LIBRARY} 
	g++ -o $@ ${LD_FLAGS} $^

${LIBRARY}:${OBJ}
	ar -rs $@ ${OBJ}

.PHONY:clean

clean:
	rm *.o -rf
	rm src/*/*.o -rf
	rm ${LIBRARY} -rf
	rm ${PROGRAMS} -rf
