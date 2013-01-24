all:libgtest.a

libgtest.a:gtest-all.o
	ar -rv $@ $< 

gtest-all.o:src/gtest-all.cc
	g++ -c -o $@ $< -Iinclude -I. -g

.PHONY:clean
clean:
	rm libgtest.a -rf 
	rm gtest-all.o -rf
