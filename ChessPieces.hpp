//This is a list of all the chess pieces and their respective moves
//Created by: Steven Reed
//Created on: 10/20/2017
//Last modified on: 10/20/2017


#ifndef CHESSPIECE_HPP
#define CHESSPIECE_HPP

#include <string>
#include <vector>

// This class is a simple representation of a chess piece. It has a type and a color.
// The type is an enum class that can be one of the following: King, Queen, Rook, Bishop, Knight, Pawn.
// The color is an enum class that can be one of the following: W, B.
// The class has two methods: get_piece_type() and get_piece_color() that return the type and color of the piece, respectively.
// the get_piece_type() method returns a string representation of the piece type.
// the get_piece_color() method returns a char representation of the piece color.
class ChessPiece {
public:
    enum class piece_type {
        King,
        Queen,
        Rook,
        Bishop,
        Knight,
        Pawn,
    };

    enum class piece_color {
        W,
        B,
    };
    // Constructor that takes a piece type and a piece color and initializes the type_ and color_ member variables.
    ChessPiece(piece_type type, piece_color color) : type_(type), color_(color) {}

    // Getters for the type_ and color_ member variables.
    std::string get_piece_type() const {
        switch (type_) {
            case piece_type::King:
                return "King";
            case piece_type::Queen:
                return "Queen";
            case piece_type::Rook:
                return "Rook";
            case piece_type::Bishop:
                return "Bishop";
            case piece_type::Knight:
                return "Knight";
            case piece_type::Pawn:
                return "Pawn";
        }
    }
    std::string get_piece_color() const {
        switch (color_) {
            case piece_color::W:
                return "White";
            case piece_color::B:
                return "Black";
        }
    }

    // Setters for the type_ and color_ member variables.
    void set_piece_type(piece_type type) {
        type_ = type;
    }
    void set_piece_color(piece_color color) {
        color_ = color;
    }

//makes sure that type_ and color_ are private so that they cannot be changed outside of the class.
private:
    piece_type type_;
    piece_color color_; // 'W' for white, 'B' for black
};

// This class represents a chess piece and its possible moves.
// It has a ChessPiece object and a vector of vectors of ints that represents the possible moves of the piece.
// The ChessPiece object represents the piece and its type and color.
// The vector of vectors of ints represents the possible moves of the piece.
// The class has a method called get_possible_moves() that returns the possible moves of the piece.
class ChessPieceMoves {

private:
    ChessPiece piece_;
    std::vector<std::vector<int>> possible_moves_;
public:
    // Constructor that takes a ChessPiece object and a vector of vectors of ints and initializes the piece_ and possible_moves_ member variables.
    ChessPieceMoves(ChessPiece piece, std::vector<std::vector<int>> possible_moves) : piece_(piece), possible_moves_(possible_moves) {}

    // Getter for the possible_moves_ member variable.
    std::vector<std::vector<int>> get_possible_moves() const {
        return possible_moves_;
    }

    // Setter for the possible_moves_ member variable.
    void set_possible_moves(std::vector<std::vector<int>> possible_moves) {
        possible_moves_ = possible_moves;
    }
};

#endif // CHESSPIECE_HPP
