# program Makefile

GCC= g++
CFLAGS= -g -Wall
OBJS= petSystemMain.o petSystem.o
EXE= mySystem

$(EXE): $(OBJS)
	$(GCC) $(OBJS) -o $(EXE)

petSystemMain.o: petSystemMain.cpp petSystem.h pet.h owner.h
	$(GCC) $(CFLAGS) -c petSystemMain.cpp

petSystem.o: petSystem.cpp petSystem.h pet.h owner.h
	$(GCC) $(CFLAGS) -c petSystem.cpp

clean:
	rm $(OBJS) $(EXE)
