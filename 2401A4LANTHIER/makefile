MAZE = mazes.o mazeDisplay.o

all: main util
	gcc -o maze $(MAZE) -lX11

main: mazes.c mazeDisplay.h graphSet.h
	gcc -c mazes.c

util: mazeDisplay.c mazeDisplay.h graphSet.h
	gcc -c mazeDisplay.c

clean:
		rm -f $(MAZE) maze
