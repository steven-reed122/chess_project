//This is the main file that will run the chess game
//Created by: Steven Reed
//Created on: 10/20/2017
//Last modified on: 10/20/2017

#include "input.hpp"
#include "ChessBoard.hpp"

void doMove (ChessBoard &board, bool &whiteTurn, std::string movingPiece, std::string newPosition, bool &legalMove);

int main() {
    bool gameOver = false;
    bool whiteTurn = true;
    bool legalMove = false;
    ChessBoard board = ChessBoard();
    std::cout << "Initialized Chess Board:" << std::endl;
    board.printBoard();
    while (!gameOver) {
        legalMove = false;
        std::string movingPiece;
        std::string newPosition;
        while (!legalMove) {
            std::cout << "It is " << (whiteTurn ? "White's" : "Black's") << " turn." << std::endl;
            movingPiece = getMovingPiece();
            newPosition = getNewPosition();
            if (movingPiece == "quit" && newPosition == "quit") {
                gameOver = true;
                break;
            }
            if (board.isMoveLegalPublic(movingPiece, newPosition)) {
                doMove(board, whiteTurn, movingPiece, newPosition, legalMove);
            } else {
                std::cout << "Illegal move, try again." << std::endl;
            }
        }
    }
    return 0;
}

void doMove (ChessBoard &board, bool &whiteTurn, std::string movingPiece, std::string newPosition, bool &legalMove) {
    if(whiteTurn) {
        if(board.getPieceColor(movingPiece) != "White") {
            std::cout << "It is not your turn, try again." << std::endl;
            return;
        }
    }
    else {
        if(board.getPieceColor(movingPiece) != "Black") {
            std::cout << "It is not your turn, try again." << std::endl;
            return;
        }
    }
    if(board.isMoveLegalPublic(movingPiece, newPosition)) {
        if(!legalMove) {
            legalMove = true;
            whiteTurn = !whiteTurn;
            board.movePiece(movingPiece, newPosition);
            board.printBoard();
        }
    }
    else {
        std::cout << "Illegal move, try again." << std::endl;
    }
}