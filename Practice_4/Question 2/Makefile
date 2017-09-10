# program Makefile

GCC= g++
CFLAGS= -g -Wall
OBJS= template.o
EXE= mytemplate

$(EXE): $(OBJS)
	$(GCC) $(OBJS) -o $(EXE)

linkedlist.o: template.cpp
	$(GCC) $(CFLAGS) -c template.cpp

clean:
	rm $(OBJS) $(EXE)
