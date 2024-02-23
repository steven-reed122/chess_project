//This is a files that creates the chess board and defines the size of the board
//Created on: 10/20/2017
//Last modified on: 10/20/2017

#ifndef CHESS_BOARD_HPP
#define CHESS_BOARD_HPP

#include <vector>
#include <string>
#include <iostream>

// This class is a simple representation of a chess board. It has a size and a vector of vectors of strings that represents the board.
// The size is an int that represents the size of the board.
// The board is a vector of vectors of strings that represents the board. The strings are the pieces on the board.
// The class has a method called print_board() that prints the board to the console.
class ChessBoard {

private:
    int size_ ;
    std::vector<std::vector<std::string>> board_;
public:
    // Constructor that initializes a board.
    ChessBoard(int size) : size_(size) {
        board_.resize(size_, std::vector<std::string>(size_, " "));
    }

    // Getter for the size_ member variable.
    int get_size() const {
        return size_;
    }
    // Getter for the board_ member variable.
    std::vector<std::vector<std::string>> get_board() const {
        return board_;
    }
    // Setter for the board_ member variable.
    void set_board(std::vector<std::vector<std::string>> board) {
        board_ = board;
    }

    void set_piece(int x, int y, std::string piece) {
        board_[x][y] = piece;
    }

    std::string get_piece(int x, int y) {
        return board_[x][y];
    }

    // Setter for the board_ member variable.
    void set_board_nothing() {
        for (int i = 0; i < size_; i++) {
            for (int j = 0; j < size_; j++) {
                board_[i][j] = " ";
            }
        }
    }
    // Method that prints the board to the console.
    void print_board() const {
        for (int i = 0; i < size_; i++) {
            for (int j = 0; j < size_; j++) {
                std::cout << board_[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};
#endif