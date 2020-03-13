CPP=c++
SOURCES= dense-matrix.cpp  matrix-mult.cpp
OBJS=$(SOURCES:%.cpp=%.o)
INCLUDE=../include

all:  $(OBJS) test1

dense-matrix.o: dense-matrix.cpp $(INCLUDE)/dense-matrix.h 
	$(CPP) -I $(INCLUDE) -c dense-matrix.cpp

matrix-mult.o:  matrix-mult.cpp $(INCLUDE)/matrix-mult.h $(INCLUDE)/dense-matrix.h
	$(CPP) -I $(INCLUDE) -c matrix-mult.cpp

test1: test1.cpp $(INCLUDE)/dense-matrix.h $(INCLUDE)/matrix-mult.h $(OBJS)
	$(CPP) -v -I ../include -c test1.cpp 
	$(CPP) -v -o test1 test1.o $(OBJS)

clean:
	@-rm $(OBJS) test1 test1.o

.PHONY: all clean

