//Implements the ChessBoard class
//Created by: Steven Reed and Landon Truong
//Created on: 10/20/2017
//Last modified on: 10/20/2017


#include <iostream>
#include <vector>
#include "ChessBoard.hpp"


int main() {
    ChessBoard board = ChessBoard();
    board.movePiece("d7", "d5");
    board.printBoard();
    board.movePiece("e2", "e4");
    board.printBoard();
    board.movePiece("e7", "e5");
    board.printBoard();
    board.movePiece("d1", "g4");
    board.printBoard();
    board.movePiece("d8", "e7");
    board.printBoard();
    board.movePiece("f1", "d3");
    board.printBoard();
    board.movePiece("c8", "e6");
    board.printBoard();
    board.movePiece("g1", "f3");
    board.printBoard();
    board.movePiece("b8", "c6");
    board.printBoard();
    board.movePiece("g4", "e6");
    board.printBoard();
    board.movePiece("e8", "c8");
    board.printBoard();
    board.movePiece("d4", "e5");
    board.printBoard();
    board.movePiece("f7", "f5");
    board.printBoard();
    board.movePiece("e5", "f6");
    board.printBoard();
    board.movePiece("e7", "e6");
    board.printBoard();
    board.movePiece("e1", "g1");
    board.printBoard();
    board.movePiece("e8", "c8");
    board.printBoard();
    return 0;
}


/*
    board.movePiece("a2", "a4");
    board.printBoard();
    board.movePiece("a4", "a3");
    board.printBoard();
    board.movePiece("b7", "b5");
    board.printBoard();
    board.movePiece("a4", "b5");
    board.printBoard();
    board.movePiece("c8", "a6");
    board.printBoard();
    std::vector<std::pair<int, int>> path = board.parsePath(0,0,7,7);
    for (auto p : path) {
        std::cout << p.first << ", " << p.second << std::endl;
    }
    std::cout << path.size() << std::endl;
    board.movePiece("f2", "f4");
    board.printBoard();
    board.movePiece("g8", "f6");
    board.printBoard();
    board.movePiece("g2", "g4");
    board.printBoard();
    board.movePiece("g7", "g6");
    board.printBoard();
    board.movePiece("g1", "f3");
    board.printBoard();
    board.movePiece("f8", "g7");
    board.printBoard();
    board.movePiece("f1", "h3");
    board.printBoard();
    board.movePiece("e8", "g8");
    board.printBoard();
    board.movePiece("e1", "g1");
    board.printBoard();*/


//Tests en passant, short and long castles
/*
    board.movePiece("d2", "d4");
    board.printBoard();
    board.movePiece("d7", "d5");
    board.printBoard();
    board.movePiece("e2", "e4");
    board.printBoard();
    board.movePiece("e7", "e5");
    board.printBoard();
    board.movePiece("d1", "g4");
    board.printBoard();
    board.movePiece("d8", "e7");
    board.printBoard();
    board.movePiece("f1", "d3");
    board.printBoard();
    board.movePiece("c8", "e6");
    board.printBoard();
    board.movePiece("g1", "f3");
    board.printBoard();
    board.movePiece("b8", "c6");
    board.printBoard();
    board.movePiece("g4", "e6");
    board.printBoard();
    board.movePiece("e8", "c8");
    board.printBoard();
    board.movePiece("d4", "e5");
    board.printBoard();
    board.movePiece("f7", "f5");
    board.printBoard();
    board.movePiece("e5", "f6");
    board.printBoard();
    board.movePiece("e7", "e6");
    board.printBoard();
    board.movePiece("e1", "g1");
    board.printBoard();
    board.movePiece("e8", "c8");
    board.printBoard();*/

    //Checkmate 
    /*
     board.movePiece("e2", "e4");
    board.printBoard();
    board.movePiece("e7", "e5");
    board.printBoard();
    board.movePiece("f1", "c4");
    board.printBoard();
    board.movePiece("b8", "c6");
    board.printBoard();
    board.movePiece("d1", "h5");
    board.printBoard();
    board.movePiece("d7", "d6");
    board.printBoard();
    board.movePiece("h5", "f7");
    board.printBoard();
    board.movePiece("e8", "f7");
    board.printBoard();*/

    /*
        board.movePiece("e2", "e4");
    board.printBoard();
    board.movePiece("e7", "e5");
    board.printBoard();
    board.movePiece("e1", "e2");
    board.printBoard();
    board.movePiece("f8", "c5");
    board.printBoard();
    board.movePiece("e2", "e3");
    board.printBoard();*/

    /* Stalemate
    board.movePiece("e2", "e3");
    board.movePiece("a7", "a5");
    board.movePiece("d1", "h5");
    board.movePiece("a8", "a6");
    board.movePiece("h5", "a5");
    board.movePiece("h7", "h5");
    board.movePiece("h2", "h4");
    board.movePiece("e2", "e4");
    board.movePiece("a6", "h6");
    board.movePiece("a5", "c7");
    board.movePiece("f7", "f6");
    board.movePiece("c7", "d7");
    board.movePiece("e8", "f7");
    board.movePiece("d7", "b7");
    board.movePiece("d8", "d3");
    board.movePiece("b7", "b8");
    board.movePiece("d3", "h7");
    board.movePiece("b8", "c8");
    board.movePiece("f7", "g6");
    board.movePiece("c8", "e6");
    board.printBoard();*/

    /*
        board.movePiece("h2", "h4");
    board.printBoard();
    board.movePiece("g7", "g5");
    board.printBoard();
    board.movePiece("h4", "g5");
    board.printBoard();
    board.movePiece("f7", "f6");
    board.printBoard();
    board.movePiece("g5", "f6");
    board.printBoard();
    board.movePiece("h7", "h6");
    board.printBoard();
    board.movePiece("f6", "e7");
    board.printBoard();
    board.movePiece("h6", "h5");
    board.printBoard();
    board.movePiece("e7", "d8");
    board.printBoard();
    return 0;*/