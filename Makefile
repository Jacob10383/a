CXX_FLAG = --std=c++11 -g

all: testbst
	

testbst: testbst.o bst.o
	g++ $(CXX_FLAG) -o $@ $^

testbst.o: testbst.cpp
	g++ -c $(CXX_FLAG) $^
	
bst.o: bst.cpp
	g++ -c $(CXX_FLAG) $^

clean:

	rm /f  testbst.exe *.o