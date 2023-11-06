/**
 * gameheader.h
 * CSE 332S
 * Lab Num: 3
 * Author: Jared Allen
*/

#pragma once

#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum randomEnums{
    BOARD_SIZE = 5,
    BOARD_MIN = 1,
    BOARD_MAX = 3,
    ZERO_START = 0,
    MAX_MOVES = 9,
};

enum GameSuccessValues{
    PLAYER_WON, VALID_MOVE, QUIT,GAME_OVER, GAME_QUIT, DRAW, TURN_DONE,
    OCCUPIED_SPACE, INVALID_INPUT, OUT_OF_BOUNDS
};

enum usage_fxn_values{
    PROGRAM_NAME_INDEX=0, CORRECT_NUMBER=2, IMPROPER_ARGUMENTS=22
};





class TicTacToeGame {
        public:
        TicTacToeGame(); // Constructor declaration
        friend std::ostream& operator<<(std::ostream& os, const TicTacToeGame& game);
        bool done();
        bool draw();
        int prompt(unsigned int& x,unsigned int& y);
        int turn();
        int play();
        int moveCount;
        char gameBoard[BOARD_SIZE][BOARD_SIZE];
        char currentPlayer;
        char winningPlayer;

        vector<string> playerXMoves;
        vector<string> playerOMoves;


};

int usage_fxn(char * program_name, char * command_line_argument);
