//Implements the ChessBoard class
//Created by: Steven Reed
//Created on: 10/20/2017
//Last modified on: 10/20/2017

#include "ChessBoard.hpp"
#include "ChessPieces.hpp"
#include <iostream>

void makeBoard(int size) {
    int boardSize = 8;
    ChessBoard board =  ChessBoard(boardSize);
    for (int i = 0; i < boardSize; i++) {
        board[i] = new ChessPiece*[boardSize];
    }
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            board[i][j] = nullptr;
        }
    }
}

int ChessBoard::getBoardSize() {
    return boardSize;
}


