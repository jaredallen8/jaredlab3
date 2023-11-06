/**
 * TicTacToeClass.cpp
 * CSE 332S
 * Lab Num: 3
 * Author: Jared Allen
*/
using namespace std;
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include "gameheader.h"


TicTacToeGame::TicTacToeGame(){

        for (int i = ZERO_START; i < BOARD_SIZE; i++) {
            for (int j = ZERO_START; j < BOARD_SIZE; j++) {
                gameBoard[i][j] = ' ';
            }
        }

    }

bool TicTacToeGame::done(){ // CE - Hard-coded constants all throughout this thing
    //check x's
    if ((gameBoard[1][1] == 'x') && (gameBoard[1][2] == 'x' ) && (gameBoard[1][3] == 'x')){ 
        winningPlayer = 'x';
        return true;

    }
    if ((gameBoard[2][1] == 'x') && (gameBoard[2][2] == 'x' ) && (gameBoard[2][3] == 'x')){
        winningPlayer = 'x';
        return true;

    }
    if ((gameBoard[3][1] == 'x') && (gameBoard[3][2] == 'x' ) && (gameBoard[3][3] == 'x')){
        winningPlayer = 'x';
        return true;

    }
    if ((gameBoard[1][1] == 'x') && (gameBoard[2][1] == 'x' ) && (gameBoard[3][1] == 'x')){
        winningPlayer = 'x';
        return true;

    }
    if ((gameBoard[1][2] == 'x') && (gameBoard[2][2] == 'x' ) && (gameBoard[3][2] == 'x')){
        winningPlayer = 'x';
        return true;

    }
    if ((gameBoard[1][3] == 'x') && (gameBoard[2][3] == 'x' ) && (gameBoard[3][3] == 'x')){
        winningPlayer = 'x';
        return true;

    }
    if ((gameBoard[1][3] == 'x') && (gameBoard[2][3] == 'x' ) && (gameBoard[3][3] == 'x')){
        winningPlayer = 'x';
        return true;

    }
    if ((gameBoard[1][3] == 'x') && (gameBoard[2][2] == 'x' ) && (gameBoard[3][1] == 'x')){
        winningPlayer = 'x';
        return true;

    }
    if ((gameBoard[1][1] == 'x') && (gameBoard[2][2] == 'x' ) && (gameBoard[3][3] == 'x')){
        winningPlayer = 'x';
        return true;

    }

    //check o's
    if ((gameBoard[1][1] == 'o') && (gameBoard[1][2] == 'o' ) && (gameBoard[1][3] == 'o')){
        winningPlayer = 'o';
        return true;
    }
    if ((gameBoard[2][1] == 'o') && (gameBoard[2][2] == 'o' ) && (gameBoard[2][3] == 'o')){
        winningPlayer = 'o';
        return true;
    }
    if ((gameBoard[3][1] == 'o') && (gameBoard[3][2] == 'o' ) && (gameBoard[3][3] == 'o')){
        winningPlayer = 'o';
        return true;
    }
    if ((gameBoard[1][1] == 'o') && (gameBoard[2][1] == 'o' ) && (gameBoard[3][1] == 'o')){
        winningPlayer = 'o';
        return true;
    }
    if ((gameBoard[1][2] == 'o') && (gameBoard[2][2] == 'o' ) && (gameBoard[3][2] == 'o')){
        winningPlayer = 'o';
        return true;
    }
    if ((gameBoard[1][3] == 'o') && (gameBoard[2][3] == 'o' ) && (gameBoard[3][3] == 'o')){
        winningPlayer = 'o';
        return true;
    }
    if ((gameBoard[1][3] == 'o') && (gameBoard[2][3] == 'o' ) && (gameBoard[3][3] == 'o')){
        winningPlayer = 'o';
        return true;
    }
    if ((gameBoard[1][3] == 'o') && (gameBoard[2][2] == 'o' ) && (gameBoard[3][1] == 'o')){
        winningPlayer = 'o';
        return true;
    }
    if ((gameBoard[1][1] == 'o') && (gameBoard[2][2] == 'o' ) && (gameBoard[3][3] == 'o')){
        winningPlayer = 'o';
        return true;

    }

    return false;
}

bool TicTacToeGame::draw(){
    //check for if game board is full

    moveCount = 0;
    for (int i=BOARD_MIN; i<=BOARD_MAX; i++){
        for (int j=BOARD_MIN; j<=BOARD_MAX; j++){
            if (gameBoard[i][j] != ' '){
                moveCount++;
            }
        }
    }
    if ((moveCount == MAX_MOVES)){
        return true;
    }


    return false;
}

int TicTacToeGame::prompt(unsigned int& x,unsigned int& y) {
        string input;
        cout << "Enter a valid move or enter 'quit': " << endl;
        getline(cin,input);

       input.erase(std::remove(input.begin(), input.end(), ' '), input.end());


        if (input == "quit") {
            cout << "You have quit the game. ";
            return QUIT;
        }



        for (int i = ZERO_START; i < input.length(); ++i) {
            if (input[i] == ',') {
                input[i] = ' ';
            }
        }


        istringstream iss(input);
        // check if x and y are extracted
        if (iss >> x >> y) {
            //check if inbounds
            if (((x >= BOARD_MIN) && (x <= BOARD_MAX)) && ((y >= BOARD_MIN) && (y <= BOARD_MAX))) {
                if (y == BOARD_MIN) {
                    y = BOARD_MAX;
                } else if (y == BOARD_MAX) {
                    y = BOARD_MIN;
                }

                if (gameBoard[y][x] == ' ') {
                    return VALID_MOVE;
                } else {
                    return OCCUPIED_SPACE;
                }


            }
            else{
                return OUT_OF_BOUNDS;
            }


        }
        else{
            return INVALID_INPUT;
        }


    }



int TicTacToeGame::turn() {
    cout << "\nIt is player " << currentPlayer << "'s turn" << endl;
    unsigned int xMove;
    unsigned int yMove;
    int promptValue = GAME_QUIT;

    while (promptValue != VALID_MOVE){
        promptValue = prompt(xMove,yMove);
        if (promptValue == VALID_MOVE){

            gameBoard[yMove][xMove] = currentPlayer;
            cout << *this << endl;
            cout << endl;

            string move;

            if (yMove == BOARD_MIN) {
                yMove = BOARD_MAX;
            }

            else if (yMove == BOARD_MAX) {
                yMove = BOARD_MIN;
            }
            move = to_string(xMove) + ", " + to_string(yMove) + ";";



            if (currentPlayer == 'x'){
                playerXMoves.push_back(move);
                cout << "Player x's Moves: ";
                for (const string& str : playerXMoves) {
                    cout << str << " " ;
                }
            }

            if (currentPlayer == 'o'){
                playerOMoves.push_back(move);
                cout << "Player o's Moves: ";
                for (const string& str : playerOMoves) {
                    cout << str << " " ;
                }

            }


//switch turns
            if (currentPlayer == 'x') {
                currentPlayer = 'o';
            }
            else if (currentPlayer == 'o') {
                currentPlayer = 'x';
            }

            return TURN_DONE;

        }

        else if (promptValue == QUIT){
            return GAME_QUIT;
        }

        else{
            cout << "Move invalid. Valid inputs follow the format 'x,y' (no spaces). Enter values betwee 1 and 3"  << endl;
        }
    }


}


int TicTacToeGame::play(){
    cout << *this << endl;
    currentPlayer = 'x';
    while (true){
        int turnValue;
        turnValue = turn();
        if (done() == true){
            cout << "Player " << winningPlayer << " won the game!" << endl;
            return PLAYER_WON;
        }
        if (draw() == true){
            cout << endl;
            cout << moveCount << " moves have been made. " << endl;
            cout << "No winning moves remain." << endl;
            return DRAW;

        }
        if (turnValue == GAME_QUIT){
            cout << " " << moveCount << " moves have been made." << endl;
            return GAME_QUIT;
        }

    }


}


    ostream &operator<<(ostream &os, const TicTacToeGame &game) {
        // Print the game board with labels
        for (int i = ZERO_START; i < BOARD_SIZE; i++) {
            os << BOARD_SIZE - 1 - i << " ";
            for (int j = ZERO_START; j < BOARD_SIZE; j++) {
                os << game.gameBoard[i][j];
            }
            os << '\n';
        }
        os << "  01234\n";
        return os;
    }

int usage_fxn(char * program_name, char * command_line_argument) {
    cout << "usage: " << program_name << " " << command_line_argument << endl;
    return IMPROPER_ARGUMENTS;
}





