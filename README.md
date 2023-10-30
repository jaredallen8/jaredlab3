# CSE 332 Lab Base
Repository for submitting lab work

Note: We will read this file as raw text rather than markdown.

Name: Jared Allen
Lab #: 3

Document your lab work here according to the lab specification

Errors:
I did not encounter any errors while I was making this program.


Test Trials:

Test 1 - Invalid Inputs(Letters):

It is player x's turn
Enter a valid move or enter 'quit':
Testing Testing Testing
Move invalid. Valid inputs follow the format 'x,y' (no spaces). Enter values betwee 1 and 3
Enter a valid move or enter 'quit':

Summary: This test checks that the program can appropiately handle words and
correctly reprompts the user for a correct input.


Test 2 - Invalid Inputs(spacing):

It is player x's turn
Enter a valid move or enter 'quit':
1 1
Move invalid. Valid inputs follow the format 'x,y' (no spaces). Enter values betwee 1 and 3
Enter a valid move or enter 'quit':

Summary: This test checks that the program can appropiately handle improper spacing and 
correctly reprompts the user for a correct input.

Test 3 - Invalid Inputs(out of bounds):

It is player x's turn
Enter a valid move or enter 'quit':
5,5
Move invalid. Valid inputs follow the format 'x,y' (no spaces). Enter values betwee 1 and 3
Enter a valid move or enter 'quit':

Summary: This test checks that the program can appropiately handle out of bonds inputs and
correctly reprompts the user for a correct input.

Test 4 - Quitting:

It is player x's turn
Enter a valid move or enter 'quit':
quit
You have quit the game.  0 moves have been made.

Summary: This tests checks that the program can quit when 'quit' is supplied as a user input. 
Program responds appropiately by quitting and display moves made.

Test 5 - Valid Inputs:

t is player x's turn
Enter a valid move or enter 'quit':
1,3
4      
3  x   
2      
1      
0      
  01234


Player x's Moves: 1, 3;

Summary: Test checks that the program can take in valid inputs and 
move the pieces on the board.

Test 6 - Player Winning: 

4      
3  x   
2  x   
1  xoo
0      
  01234


Player x's Moves: 1, 2; 1, 1; 1, 3; Player x won the game!

Summary: Test checks that 3-in-a-row will result in the game ending and a winner being declared.


Test 7 - Draw (No Moves Remaining): 

4      
3  xoo
2  oxx
1  xxo
0      
  01234


Player x's Moves: 1, 3; 1, 1; 2, 2; 3, 2; 2, 1;
9 moves have been made.
No winning moves remain.

9 moves have been made.
No winning moves remain.

Summary: This test checks that the game will draw once the game board is full and no moves can be made.

Test 8 - Usage Function:
usage: /Users/jaredallen/CLionProjects/lab3-jaredallen8/cmake-build-debug/src/lab_x TicTacToe

Summary: Program displays usage function and unique exit code when incorrect arguments are passed into the program.



