all: main util
	gcc -o mains main.o linked_list.o person.o

main: main.c linked_list.h person.h
	gcc -c main.c

util: linked_list.c person.c linked_list.h person.h
	gcc -c linked_list.c person.c


