101104851 Raden Mathieu Almaden

Source files : encode.c , decode.c , corrupt.c , fix.c

Compile: encode.c , fix.c , corrupt .c by inputting
"gcc -o <filename> <filename>.c"
in the terminal

For compiling decode.c, input 
"gcc -o decode decode.c -lm"
(necessary to compile the program to run math functions) in the terminal

For running encode:
Run the executable file and input anything

For running decode and corrupt:
Run the executable files and input any bits in only multiples of 12 otherwise program will exit

For running fix:
Run the executable file and input any returned sequence from corrupt or by flipping one of the 12 bits in a correct sequence

