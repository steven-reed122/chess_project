//Implements the ChessBoard class
//Created by: Steven Reed
//Created on: 10/20/2017
//Last modified on: 10/20/2017

#include <iostream>
#include <vector>

// Function to initialize the chess board
std::vector<std::vector<int> > initializeChessBoard() {
    // Create an 8x8 vector initialized with zeros
    std::vector<std::vector<int> > chessBoard(8, std::vector<int>(8, 0));
    return chessBoard;
}

// Function to print the chess board
void printChessBoard(const std::vector<std::vector<int> >& chessBoard) {
    // Iterate over the rows and columns of the chess board
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            // Print the value of each square
            std::cout << chessBoard[row][col] << " ";
        }
        // Move to the next line after printing each row
        std::cout << std::endl;
    }
}

int main() {
    // Initialize the chess board
    std::vector<std::vector<int> > chessBoard = initializeChessBoard();

    // Print the initialized chess board
    std::cout << "Initialized Chess Board:" << std::endl;
    printChessBoard(chessBoard);

    return 0;
}
