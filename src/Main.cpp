/**
 * Main.cpp
 * CSE 332S
 * Lab Num: 3
 * Author: Jared Allen
*/

#include <iostream>
#include "gameheader.h"

using namespace std;

#include <iostream> // CE - Probably shouldn't include iostream twice


int main(int argc, char * argv[] ) {
    if (argc != CORRECT_NUMBER){
        usage_fxn(argv[PROGRAM_NAME_INDEX], "TicTacToe");
        return IMPROPER_ARGUMENTS;
    }
    else{
        TicTacToeGame game;
        return game.play();;

    }

}
