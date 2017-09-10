# program Makefile

GCC= g++
CFLAGS= -g -Wall
OBJS= linkedlistMain.o linkedlist.o
EXE= mylinkedlist

$(EXE): $(OBJS)
	$(GCC) $(OBJS) -o $(EXE)

linkedlistMain.o: linkedlistMain.cpp linkedlist.h
	$(GCC) $(CFLAGS) -c linkedlistMain.cpp

linkedlist.o: linkedlist.cpp linkedlist.h
	$(GCC) $(CFLAGS) -c linkedlist.cpp

clean:
	rm $(OBJS) $(EXE)
