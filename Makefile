IDIR = ./include
CC = g++
CFLAGS = -I$(IDIR)

#OBJS specifies which files to compile as part of the project
OBJS = ./src/main.cpp ./src/graphics.cpp ./src/distributions.cpp

#linker flags
LINKER_FLAGS = -lSDL2 -lSDL2_ttf

#name of the executable
OBJ_NAME = program

#compile
all : $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LINKER_FLAGS) -o ./bin/$(OBJ_NAME)
