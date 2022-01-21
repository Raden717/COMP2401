Developer: Raden Mathieu Almaden ID:101104851

Development Date: November 10 2019

Purpose of Software: To assist the design team with creating a linked list program to be used for manipulating records of employees and students at Carleton and including test scenarios for said functions from the linked list program.

Source Files:
linked_list.c
main.c
person.c

Header Files:
linked_list.h
person.h

MakeFiles:
makefile

Compiling Command:
make

Execution Command:
./mains					Just for running the test file main
valgrind --leak-check=yes ./mains	Testing the test file main for any memory leaks

Limitation Problems:
This program is only responsible for running linked list for a specific structure. That structure being PersonInfo. Trying to use this linked list for any other structure will fail as the functions for the linked lists will only work for this specific structure.

How to use the software:

To use the software with your own files that are similar to the main source file. You will need to include the header files in your program to be able to use the linked list functions. You will also need to adjust the makefile in accordance to your files opposed to the included main file unless you decide to go with the same filename. After doing all of this or just deciding to test the orginal main file. You will need to open a terminal within the directory containing the source and header files. After opening the terminal, run the compiling command and then the execution command. This will run the software and the testing file. If you would like to edit or look at any of the functions in the linked list, you will need to open the linked_list.c source file with any IDE of your choice.
