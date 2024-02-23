//Implements the ChessBoard class
//Created by: Steven Reed
//Created on: 10/20/2017
//Last modified on: 10/20/2017

#include "ChessBoard.hpp"
#include "ChessPieces.hpp"
#include <iostream>

int main()
{
    ChessBoard board = ChessBoard(8);
    board.set_board_nothing();
    board.print_board();
    return 0;
}