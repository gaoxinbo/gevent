LIBRARY=libgevent.a
PROGRAMS=listen_server connection
GTEST=libgtest.a
TEST=test_status


all:${LIBRARY} ${PROGRAMS} ${GTEST} ${TEST} 

libgtest.a:
	(cd gtest;make)

## automatic generate source file list
${shell ./build_config.sh}
include build_config.mk

GTEST_DIR=gtest

OBJ=${SOURCE:.cc=.o}

INCLUDE=-Isrc -I${GTEST_DIR}/include
CXX_FLAGS=-g -O2 -Wall -Werror ${INCLUDE}
LD_FLAGS=-g -lpthread


test_status:src/util/status_test.o
	g++ -o $@ $< ${CXX_FLAGS} ${LD_FLAGS} ${GTEST_DIR}/${GTEST} ${LIBRARY}

check:${LIBRARY} ${TEST}
	for t in ${TEST};do echo "running $$t......"; ./$$t || exit 1; done

.cc.o:
	g++ -c ${CXX_FLAGS} $< -o $@

listen_server:src/example/listen_server.o ${LIBRARY} 
	g++ -o $@ ${LD_FLAGS} $^

connection:src/example/connection.o ${LIBRARY} 
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
	rm ${TEST} -rf
  
