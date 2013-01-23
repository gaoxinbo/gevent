LIBRARY=libgevent.a
PROGRAMS=

all:${LIBRARY} 

LIBRARY_SOURCE=src/net/socket.cc \
               src/net/inetaddress.cc \
               src/net/eventhandler.cc \
               src/net/accepter.cc

OBJ=${LIBRARY_SOURCE:.cc=.o}

CXX_FLAGS=-g -O2 -Wall -Werror -Isrc

.cc.o:
	g++ -c ${CXX_FLAGS} $< -o $@

${LIBRARY}:${OBJ}
	ar -rs $@ ${OBJ}

.PHONY:clean

clean:
	rm *.o -rf
	rm src/*/*.o -rf
	rm ${LIBRARY} -rf
