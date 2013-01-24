LIBRARY=libgevent.a
PROGRAMS=listen_server
GTEST=libgtest.a


all:${LIBRARY} ${PROGRAMS} ${GTEST} 

libgtest.a:
	(cd gtest;make)

## automatic generate source file list
${shell ./build_config.sh}
include build_config.mk

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
	(cd gtest;make clean)
	rm *.o -rf
	rm src/*/*.o -rf
	rm ${LIBRARY} -rf
	rm ${PROGRAMS} -rf
