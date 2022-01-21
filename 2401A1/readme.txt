Raden Mathieu Almaden 101104851
Source files: patioBuilder.c , cards.c


To compile patioBuilder.c, 

Open a terminal within the folder 2401A1 containing patioBuilder.c , or traverse the terminal till you reach the directory 2401A1.

Once reached, type the command
	gcc -o patioBuilder patioBuilder.c -lm
IT is very important to follow this command exactly, otherwise the c file will not compile. It is necessary for -lm to be included into this command

To run patioBuilder executable after compiling, type the command
	./patioBuilder
within the same directory.

When the file is ran, the first user input will be needed
the input will ask you to input a length for your patio in feet, insert any number you would like. However, the input needs to be over certain limit (24 inches) otherwise the program will end.
If you input a proper length, it will ask for another input, it will ask you to input the width of your patio in feet. The same limitations from the previous input apply here.
After passing both, the program will print out the necessary information.



To compile cards.c

Open a terminal within the folder 2401A1 containing patioBuilder.c , or traverse the terminal till you reach the directory 2401A1.

Once reached, type the command
	gcc -o cards cards.c

To run cards executable after compiling, type the command
	./cards
within the same directory

When the file is ran, it will ask for a user input for a Trump Card, enter a valid input. After this it will ask the user to input a valid card for the first player. Enter another valid input. This will continue until four players have chosen valid cards.
It will then print which player has won based on certain condtions and then the entire process will repeat again until the user decides to exit.
To exit, first you will need to enter a valid Trump Card, then you will have to type ',' as the first character and a valid suit ('C','H','S','D') when inputting for ANY of the 4 players to end the program. Otherwise the program will continuosly repeat.


