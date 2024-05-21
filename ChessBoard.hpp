//This is a files that contains the chess board class
//Written by Steven Reed amd Landon Truong
//Created on: 2/20/2024
//Last modified on: 3/1/2024

// This class is a simple representation of a chess board. It has a size and a vector of vectors of ints that represents the board.
// 1 = pawn, 2 = knight, 3 = bishop, 4 = rook, 5 = queen, 6 = king, 0 = empty square
// The size is an int that represents the size of the board.
// The method printBoard() prints the board to the console.

#ifndef CHESS_BOARD_HPP
#define CHESS_BOARD_HPP

#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <cmath>
#include <utility>
#include <algorithm>
using namespace std;


class ChessBoard {

private:
    int size_ ;
    std::vector<std::vector<int>> board_;
    std::vector<int> previousMove = {0, 0, 0, 0}; 

    //This function converts a piece name inputed from another class into an int
    //So it can be represented in the chess board
    int convertPieceNameToInt(const std::string& pieceName) const{
        static const std::unordered_map<std::string, int> pieceValues = {
            {"           ", 00},  // Mapping for an empty board square
            {"whitePawn  ", 01},
            {"whiteKnight", 02},
            {"whiteBishop", 03},
            {"whiteRook  ", 04},
            {"whiteQueen ", 05},
            {"whiteKing  ", 06},
            {"blackPawn  ", 11},
            {"blackKnight", 12},
            {"blackBishop", 13},
            {"blackRook  ", 14},
            {"blackQueen ", 15},
            {"blackKing  ", 16}
        };
    
        auto it = pieceValues.find(pieceName);
        if (it != pieceValues.end()) {
            return it->second;  // Found the piece, return its corresponding value
        } else {
            // Handle invalid piece name, maybe return -1 or throw an exception
            return -1;  // Assuming -1 as an indicator of invalid piece name
        }
    }

    //This function converts a piece int into a string so we can send it to other classes
    //So it can be represnted in the chess board
    std::string getChessPieceName(int value) const{
        static const std::unordered_map<int, std::string> valuePieces = {
            {00, "           "},
            {01, "whitePawn  "},
            {02, "whiteKnight"},
            {03, "whiteBishop"},
            {04, "whiteRook  "},
            {05, "whiteQueen "},
            {06, "whiteKing  "},
            {11, "blackPawn  "},
            {12, "blackKnight"},
            {13, "blackBishop"},
            {14, "blackRook  "},
            {15, "blackQueen "},
            {16, "blackKing  "}
        };

        auto it = valuePieces.find(value);
        if (it != valuePieces.end()) {
            return it->second;  // Found the value, return its corresponding chess piece name
        } else {
            // Handle invalid value, maybe return "invalid" or throw an exception
            return "invalid";  // Assuming "invalid" as an indicator of invalid value
        }
    }

    std::unordered_map<std::string, bool> pieceMoved = {
        {"e1", false},
        {"e8", false},
        {"a1", false},
        {"h1", false},
        {"a8", false},
        {"h8", false}
    };

    void markPieceMoved(const std::string& pieceLocation) {
        if (pieceMoved.find(pieceLocation) != pieceMoved.end()) {
            pieceMoved[pieceLocation] = true;
        } else {
            std::cerr << "Piece Location not found: " << pieceLocation << std::endl;
        }
    }

    bool hasPieceMoved(const std::string& pieceLocation) {
            return pieceMoved[pieceLocation];
    }

    std::string getPieceLocation(int x, int y) {
        std::string column = std::string(1, 'a' + x);
        std::string row = std::to_string(8 - y);
        return column + row;
    }
    
public:
    // Constructor that initializes a board.
    
    ChessBoard() : size_(8), board_(8, std::vector<int>(8, 00)) {
    // Create a vector of vectors of ints to represent the board
        {
        board_ = {
            {14, 12, 13, 15, 16, 13, 12, 14},
            {11, 11, 11, 11, 11, 11, 11, 11},
            {00, 00, 00, 00, 00, 00, 00, 00},
            {00, 00, 00, 00, 00, 00, 00, 00},
            {00, 00, 00, 00, 00, 00, 00, 00},
            {00, 00, 00, 00, 00, 00, 00, 00},
            {01, 01, 01, 01, 01, 01, 01, 01},
            {04, 02, 03, 05, 06, 03, 02, 04}
        };
        }
    }

    // Getter for the size_ member variable.
    int getSize() const {
        return size_;
    }

    // Allows us to set a piece onto the designated square on the board
    // Refer to the convertPieceNameToInt function to see what the valid piece names are
    void setSquare(int x, int y, std::string pieceName) {
        int pieceInt = convertPieceNameToInt(pieceName);
        board_[y][x] = pieceInt;
    }

    // Allows us to figure out which piece is on a given square
    std::string getSquare(int x, int y) {
        int piece = board_[y][x];
        std::string pieceName = getChessPieceName(piece);
        return pieceName;
    }

    std::string getPieceType(int x, int y) {
        int pieceInt = board_[y][x];
        std::string pieceName;
    switch(pieceInt) {
        case 0:
            pieceName = "Null"; break;
        case 1:
        case 11:
            pieceName = "Pawn"; break;
        case 2:
        case 12:
            pieceName = "Knight"; break;
        case 3:
        case 13:
            pieceName = "Bishop"; break;
        case 4:
        case 14:
            pieceName = "Rook"; break;
        case 5:
        case 15:
            pieceName = "Queen"; break;
        case 6:
        case 16:
            pieceName = "King"; break;
        default:
            pieceName = "Unknown"; break;
    }
    return pieceName;
    }

    // Method that prints the board to the console.
    // It also prints the column and row labels.
    void printBoard() const {
        for (int i = 0; i < size_; i++) {
            std::cout << 8-i << " | ";
            for (int j = 0; j < size_; j++) {
                std::cout << getChessPieceName(board_[i][j]) << "-";
            }
            std::cout << std::endl;
        }
        std::cout << "    -----------------------------------------------------------------------------------------------" << std::endl;
        std::cout << "        a           b           c           d           e           f           g           h" << std::endl;
    }


    bool isSquareEmpty(int x, int y) {
        return board_[y][x] == 00;
    }

    bool isPieceWhite(int x, int y) {
        if (board_[y][x] < 10 && board_[y][x] != 00)
            return true;
        else
            return false;
    }

    std::string getPieceColor(std::string pieceLocation) {
        std::vector<int> piece = parsePieceLocation(pieceLocation);
        int x = piece[0]; int y = piece[1];
        if (isPieceWhite(x, y)) {
            return "White";
        } else {
            return "Black";
        }
    }

    void movePiece(std::string piece1location, std::string piece2location) 
    {
        std::vector<int> piece1 = parsePieceLocation(piece1location);
        std::vector<int> piece2 = parsePieceLocation(piece2location);
        int x1 = piece1[0]; int y1 = piece1[1];
        int x2 = piece2[0]; int y2 = piece2[1];
        movePieceInt(x1, y1, x2, y2);
    }

    // Allows us to move a piece from one square to another
    // x1 and y1 are the coordinates of the piece to move
    // x2 and y2 are the coordinates of the square to move the piece to
    void movePieceInt(int x1, int y1, int x2, int y2) {
        if (isMoveLegal(x1, y1, x2, y2)) {
            //Handling for castling
            if (abs(x2 - x1) == 2 && getPieceType(x1, y1) == "King") {
                //Determine rook's original and new positions
                int rookOrigX = (x2 > x1) ? 7 : 0;
                int rookNewX = (x2 > x1) ? 5 : 3;
                bool isWhite = isPieceWhite(x1, y1);

                //Check which side is castling and whether it is kingside (short) or queenside (long)
                std::string side = (x2 > x1) ? "short" : "long";
                std::string color = isPieceWhite(x1, y1) ? "White" : "Black";

                //Print the castling move
                std::cout << color << " castles " << side << "." << std::endl;

                //Move the king and the rook to their new positions
                board_[y1][x1] = 00; //Clear the king's original square
                board_[y1][x2] = isWhite ? 06 : 16; //Move the king to the new position
                board_[y1][rookOrigX] = 00; //Clear the rook's original square
                board_[y1][rookNewX] = isWhite ? 04 : 14; //Move the rook to its new position

                //Mark the king and the rook as having moved
                markPieceMoved(getPieceLocation(x1, y1));
                markPieceMoved(getPieceLocation(rookOrigX, y1));
            } else {
                //Regular move
                int piece = board_[y1][x1];
                board_[y1][x1] = 00; //Clear the start square
                board_[y2][x2] = piece; //Set piece on destination
                previousMove = {x1, y1, x2, y2}; //Track move

                //Check for pawn promotion immediately after the move
                if ((piece == 01 && y2 == 0) || (piece == 11 && y2 == 7)) {  //Check if it's a pawn reaching the last rank
                    pawnPromotion(x2, y2);  //Handle pawn promotion
                }
            }

            //Find positions of both kings
            int whiteKingX, whiteKingY, blackKingX, blackKingY;
            findKingPositions(whiteKingX, whiteKingY, blackKingX, blackKingY);

            //Check for check conditions for both kings
            bool whiteInCheck = isPosUnderThreat(whiteKingX, whiteKingY, true);
            bool blackInCheck = isPosUnderThreat(blackKingX, blackKingY, false);

            //Handle check, checkmate, and stalemate scenarios
            handleGameStatus(whiteInCheck, blackInCheck);
        }
    }

    void handleGameStatus(bool whiteInCheck, bool blackInCheck) {
        if (whiteInCheck) {
            std::cout << "White king is in Check!" << std::endl;
            if (isCheckMate(true)) {
                std::cout << "Checkmate, Black wins!" << std::endl;
                throw std::runtime_error("Game over");
            }
        } else if (isStalemate(true)) {
            std::cout << "Stalemate, game over." << std::endl;
            throw std::runtime_error("Game over");
        }

        if (blackInCheck) {
            std::cout << "Black king is in Check!" << std::endl;
            if (isCheckMate(false)) {
                std::cout << "Checkmate, White wins!" << std::endl;
                throw std::runtime_error("Game over");
            }
        } else if (isStalemate(false)) {
            std::cout << "Stalemate, game over." << std::endl;
            throw std::runtime_error("Game over");
        }
    }

    void findKingPositions(int& whiteKingX, int& whiteKingY, int& blackKingX, int& blackKingY) {
        //Initialize positions to an invalid value, in case kings are not found (for robustness)
        whiteKingX = whiteKingY = blackKingX = blackKingY = -1;

        //Loop through the board to find the positions of the white and black kings
        for (int y = 0; y < size_; ++y) {
            for (int x = 0; x < size_; ++x) {
                if (board_[y][x] == 06) { //06 represents the white king in your piece encoding
                    whiteKingX = x;
                    whiteKingY = y;
                } else if (board_[y][x] == 16) { //16 represents the black king
                    blackKingX = x;
                    blackKingY = y;
                }
            }
        }
    }


    bool isMoveLegal(int x1, int y1, int x2, int y2) {
        std::string pieceType = getPieceType(x1, y1);
        bool isWhite = isPieceWhite(x1, y1);

        if (pieceType == "Null") {
            //std::cout << "No piece at the starting position." << std::endl;
            return false;
        }

        //Simulate the move temporarily
        int originalPiece = board_[y2][x2];
        board_[y2][x2] = board_[y1][x1];
        board_[y1][x1] = 00;

        //Check if the move places or leaves the player's king in check
        bool inCheckAfterMove = isInCheck(isWhite);

        //Undo the temporary move
        board_[y1][x1] = board_[y2][x2];
        board_[y2][x2] = originalPiece;

        //If the player's king is in check after the move, the move is illegal
        if (inCheckAfterMove) {
            //std::cout << "Move leaves king in check, move is illegal." << std::endl;
            return false;
        }

        //Check for legal move (excluding collision and specific captures)
        if (!canMoveToSquare(x1, y1, x2, y2, pieceType, isPieceWhite(x1, y1))) {
            //std::cout << "Move is Illegal" << std::endl;
            return false; 
        }

        //Collision check, applicable for all pieces except knights
        if (isCollision(x1, y1, x2, y2, pieceType)) {
            //std::cout << "Piece cannot move through other pieces." << std::endl;
            return false;
        }

        //Handle en passant capture legality
        if (pieceType == "Pawn" && abs(x2 - x1) == 1 && isSquareEmpty(x2, y2) && isEnPassantLegal(x1, y1, x2, y2)) {
            //std::cout << "En passant capture is legal." << std::endl;
            return true;
        }

        //General capture legality, including same-color capture attempt
        bool isDestinationOccupied = !isSquareEmpty(x2, y2);
        bool isMovingPieceWhite = isPieceWhite(x1, y1);
        bool isDestinationPieceWhite = isDestinationOccupied && isPieceWhite(x2, y2);
        if (isDestinationOccupied && isMovingPieceWhite == isDestinationPieceWhite) {
            //std::cout << "Cannot capture your own piece." << std::endl;
            return false;
        }

        //Special handling for castling
        if (abs(x2 - x1) == 2 && pieceType == "King" && !isDestinationOccupied) {
            bool castleLegal = isCastleLegal(getPieceLocation(x1, y1), getPieceLocation(x2, y2));
            if (!castleLegal) std::cout << "Castling move is illegal." << std::endl;
            return castleLegal;
        }

        if (pieceType == "King" && isPosUnderThreat(x2, y2, isPieceWhite(x1, y1))) {
            //std::cout << "King cannot move into check." << std::endl;
            return false;
        }

        //If reaching here, move is either a legal non-capture or a legal capture (excluding en passant handled above)
        if (isDestinationOccupied) {
            //std::cout << "Piece captured." << std::endl;
        }
        //else std::cout << "Move is legal." << std::endl;
        return true;
    }

     bool canCapture(bool isDestinationWhite, bool isWhite, bool isDestinationOccupied) {
        if (isDestinationOccupied) {
            return isDestinationWhite != isWhite;
        }
        return true;
    }

    bool isCollision(int x1, int y1, int x2, int y2, std::string pieceType) {
        if (pieceType == "Knight") {
                return false; // Knights can jump over other pieces
        }
        std::vector<std::pair<int, int>> path = parsePath(x1, y1, x2, y2);
        // Check each square along the path for collision
        for (const auto& square : path) {
            //int i = 0;
            int x = square.first;
            int y = square.second;
            if (!isSquareEmpty(x, y)) {
                return true; // Collision detected
            }
        }
        return false; // No collision detected
    }

    // returns true if a piece can move to a certain square
    // returns false if a piece cannot move to a certain square
    // this function does not consider the existence of other pieces on the board
    // all pieces function properly except for the pawn
    bool canMoveToSquare(int x1, int y1, int x2, int y2, std::string pieceType, bool isWhite) {
        // Calculate the horizontal and vertical distances between the initial and destination coordinates
        int deltaX = std::abs(x2 - x1);
        int deltaY = std::abs(y2 - y1);

        if (pieceType == "Rook") {
            // Rook can move either horizontally or vertically
            return (deltaX == 0 && deltaY > 0) || (deltaY == 0 && deltaX > 0);
        } else if (pieceType == "Bishop") {
            // Bishop can move diagonally
            return deltaX == deltaY;
        } else if (pieceType == "Queen") {
            // Queen can move horizontally, vertically, or diagonally
            return (deltaX == 0 && deltaY > 0) || (deltaY == 0 && deltaX > 0) || (deltaX == deltaY);
        } else if (pieceType == "King") {
            if(deltaX <= 1 && deltaY <= 1) {
                return true;
            } else if (deltaX == 2 && deltaY == 0) {
                std::string piece1Location = getPieceLocation(x1, y1);
                std::string piece2Location = getPieceLocation(x2, y2);
                return isCastleLegal(piece1Location, piece2Location);
            }
            return false;
        } else if (pieceType == "Knight") {
            // Knight can move in an L-shape
            return (deltaX == 1 && deltaY == 2) || (deltaX == 2 && deltaY == 1);
        } else if (pieceType == "Pawn") {
            deltaX = x2 - x1;  
            deltaY = y2 - y1;  
            int direction = isWhite ? -1 : 1;  //Determines the direction of the pawn based on its color

            //Forward movement without capturing
            if (deltaX == 0 && deltaY == direction) {
                if (isSquareEmpty(x2, y2)) {
                    //cout << "Pawn moves forward one square" << endl;
                    return true;
                }
                return false;
            }
            //Initial double step movement from starting position
            else if (deltaX == 0 && deltaY == 2 * direction && ((isWhite && y1 == 6) || (!isWhite && y1 == 1))) {
                if (isSquareEmpty(x2, y2) && isSquareEmpty(x2, y1 + direction)) {
                    //cout << "Pawn moves forward two squares" << endl;
                    return true;
                }
                return false;
            }
            //Capturing diagonally
            else if (abs(deltaX) == 1 && deltaY == direction) {
                if (!isSquareEmpty(x2, y2) && isPieceWhite(x2, y2) != isWhite) {
                    //cout << "Pawn captures diagonally" << endl;
                    return true;
                }
                else if (isEnPassantLegal(x1, y1, x2, y2)) {
                    //cout << "En passant capture" << endl;
                    setSquare(x2, y1, "           ");
                    return true;
                }
                return false;
            }
        }

        else if (pieceType == "Null") {
            //std::cout << "No piece at the initial position" << std::endl;
            return false; // Invalid piece type
            }
        else {
            //std::cout << "Invalid move for a weird reason" << std::endl;
            return false; // Invalid move
        }

        // Invalid piece type or invalid move
        //std::cout << "Invalid move" << std::endl;
        return false;
    }

    std::vector<int> parsePieceLocation(const std::string& pieceLocation) {
        std::vector<int> result(2);

        // Ensure the input is of the correct length and format
        if (pieceLocation.size() != 2 || !isalpha(pieceLocation[0]) || !isdigit(pieceLocation[1])) {
            std::cerr << "Invalid piece location format." << std::endl;
            return result;
        }
        // Map the column character to its corresponding index
        // If its out of bounds return an error
        result[0] = std::tolower(pieceLocation[0]) - 'a';
        if (result[0] < 0 || result[0] > size_ - 1) {
            std::cerr << "Invalid column character, or out of bounds" << std::endl;
            return result;
        }
        // Map the row character to its corresponding index
        result[1] = '8' - pieceLocation[1];
        if (result[1] < 0 || result[1] > size_ - 1) {
            std::cerr << "Invalid row character, or out of bounds" << std::endl;
            return result;
        }
        return result;
    }

    std::vector<std::pair<int, int>> parsePath(int x1, int y1, int x2, int y2) {
        std::vector<std::pair<int, int>> path;
        int deltaX = std::abs(x2 - x1);
        int deltaY = std::abs(y2 - y1);

        // Determine direction of movement
        int stepX = (x2 > x1) ? 1 : ((x2 < x1) ? -1 : 0);
        int stepY = (y2 > y1) ? 1 : ((y2 < y1) ? -1 : 0);

        // Generate path from (x1, y1) to (x2, y2)
        int x = x1 + stepX;
        int y = y1 + stepY;
        while (x != x2 || y != y2) {
            path.push_back(std::make_pair(x, y));
            x += stepX;
            y += stepY;
        }
        return path;
    }

    bool isEnPassantLegal(int x1, int y1, int x2, int y2) {
        // Check if the move is a valid en passant move
        // En passant is only valid if the pawn is moving diagonally
        // and the destination square is empty
        // It must diagonally pass a pawn that just moved two squares forward
        if (isSquareEmpty(x2, y2)) {
            if (isPieceWhite(x1, y1) && !isPieceWhite(x2, y1) && isSquareEmpty(x2, y2) && y1 == 3 && y2 == 2 && previousMove[0] == x2  && previousMove[1] == 1 && previousMove[2] == x2 && previousMove[3] == 3) {
                return true;
            } else if (!isPieceWhite(x1, y1) && isPieceWhite(x2, y1) && isSquareEmpty(x2, y2) && y1 == 4 && y2 == 5 && previousMove[0] == x2  && previousMove[1] == 6 && previousMove[2] == x2 && previousMove[3] == 4) {
                return true;
            }
        }
        return false;
    }

    bool isInCheck(bool isWhite) {
        //Search board for king's position
        for (int y = 0; y < size_; ++y) {
            for (int x = 0; x < size_; ++x) {
                if ((isWhite && board_[y][x] == 06) || (!isWhite && board_[y][x] == 16)) {
                    //Determine if the king's position is under threat
                    return isPosUnderThreat(x, y, isWhite);
                }
            }
        }
        return false; //King is not in check
    }

    bool isCastleLegal(std::string piece1location, std::string piece2location) {
        std::vector<int> piece1Coords = parsePieceLocation(piece1location);
        int x1 = piece1Coords[0], y1 = piece1Coords[1];
        bool isWhite = isPieceWhite(x1, y1);

        //Correct startY for black and white pieces to reflect their respective ranks.
        int startY = isWhite ? 7 : 0; //Adjust for white (y=7) or black (y=0).
        //cout << "Checking castling for " << (isWhite ? "White" : "Black") << " king at " << piece1location << endl;

        std::string rookPosition;
        int direction, rookOrigX, endX;

        //Determine the rook's original position and direction based on castling side.
        if ((piece2location == "g1" && isWhite) || (piece2location == "g8" && !isWhite)) {
            rookPosition = isWhite ? "h1" : "h8";
            direction = 1;
            rookOrigX = 7;
            endX = x1 + 2;
            //cout << "Kingside castling initiated." << endl;
        } else if ((piece2location == "c1" && isWhite) || (piece2location == "c8" && !isWhite)) {
            rookPosition = isWhite ? "a1" : "a8";
            direction = -1;
            rookOrigX = 0;
            endX = x1 - 2;
            //cout << "Queenside castling initiated." << endl;
        } else {
            //cout << "Invalid castling attempt." << endl;
            return false;
        }

        //cout << "Rook position for castling: " << rookPosition << endl;

        //Check if the king and the corresponding rook have not moved.
        if (!hasPieceMoved(piece1location) && !hasPieceMoved(rookPosition)) {
            //cout << "Neither king nor rook have moved before." << endl;

            //Check if all squares between the king and the rook are empty.
            for (int x = x1 + direction; x != endX + direction; x += direction) {
                if (!isSquareEmpty(x, startY)) {
                    //cout << "Square " << x << "," << startY << " is not empty, castling blocked." << endl;
                    return false;
                }
            }

            //Check if the squares the king moves through are not under attack.
            for (int x = x1; x != endX + direction; x += direction) {
                if (isPosUnderThreat(x, startY, isWhite)) {
                    //cout << "Square " << x << "," << startY << " is under threat, castling not safe." << endl;
                    return false;
                }
            }
            //cout << "Castling is legal and safe." << endl;
            return true;
        } else {
            //cout << "Castling is illegal, either king or rook has moved." << endl;
        }
        return false;
    }

    bool isMoveLegalPublic(std::string piece1location, std::string piece2location) {
        std::vector<int> piece1 = parsePieceLocation(piece1location);
        std::vector<int> piece2 = parsePieceLocation(piece2location);
        int x1 = piece1[0]; int y1 = piece1[1];
        int x2 = piece2[0]; int y2 = piece2[1];
        return isMoveLegal(x1, y1, x2, y2);
    }

    bool isPosUnderThreat(int x, int y, bool isWhite) {
        //Iterate over all squares on the board to find if any piece threatens the position (x, y)
        //cout << "Checking if position " << x << "," << y << " is under threat for " << (isWhite ? "White" : "Black") << endl;
        for (int y1 = 0; y1 < size_; ++y1) {
            for (int x1 = 0; x1 < size_; ++x1) {
                int piece = board_[y1][x1];

                //Skip empty squares and same color pieces
                if (piece == 00 || isPieceWhite(x1, y1) == isWhite) continue; 
                
                std::string pieceType = getPieceType(x1, y1);
                //cout << "Evaluating threat from piece " << pieceType << " at " << x1 << "," << y1 << endl;

                //For pieces that aren't pawns, check if they can legally move to the given square, indicating a threat.
                if (pieceType != "Pawn" && canMoveToSquare(x1, y1, x, y, pieceType, !isWhite) && !isCollision(x1, y1, x, y, pieceType)) {
                    //cout << "Threat by " << pieceType << " at " << x1 << "," << y1 << endl;
                    return true;
                //For pawns, specifically check for capture ability, which is different from their movement.
                } else if (pieceType == "Pawn" && isPawnThreat(x1, y1, x, y, !isWhite)) {
                    //cout << "Threat by Pawn at " << x1 << "," << y1 << endl;
                    return true;
                }
            }
        }
        //cout << "No threat found at " << x << "," << y << endl;
        return false; //No threat found
    }

    bool isPawnThreat(int x1, int y1, int targetX, int targetY, bool isPawnWhite) {
        int captureDirection = isPawnWhite ? -1 : 1; //Pawns move up (-1) if white, down (+1) if black
        //Check if the target square is diagonally in front of the pawn
        return (y1 + captureDirection == targetY) && (abs(x1 - targetX) == 1);
    }
    
    bool isCheckMate(bool isWhite) {
        if (!isInCheck(isWhite)) {
            //std::cout << "Not in check." << std::endl;
            return false;
        }

        for (int y = 0; y < size_; ++y) {
            for (int x = 0; x < size_; ++x) {
                //Skip empty squares or pieces of the same color
                if (isPieceWhite(x, y) != isWhite || board_[y][x] == 00) continue;

                //Try all possible moves to see if check can be escaped
                for (int newY = 0; newY < size_; ++newY) {
                    for (int newX = 0; newX < size_; ++newX) {
                        //Check if the move is legal and does not result in a check
                        if (isMoveLegal(x, y, newX, newY)) {
                            //std::cout << "Escape move found from " << x << "," << y << " to " << newX << "," << newY << std::endl;
                            return false; //Found a legal move that escapes check, therefore it's not checkmate
                        }
                    }
                }
            }
        }   
        std::cout << "No legal move found to escape check: Checkmate." << std::endl;
        return true; //If no legal moves can escape check, it's checkmate
    }

    bool isStalemate(bool isWhite) {
        //Check if the next player (opposite color of isWhite) has any legal moves
        bool nextPlayerIsWhite = !isWhite;

        if (isInCheck(nextPlayerIsWhite)) {
            //std::cout << (nextPlayerIsWhite ? "White" : "Black") << " is in check, not a stalemate." << std::endl;
            return false; //If the player is in check, it cannot be a stalemate
        }

        for (int y = 0; y < size_; ++y) {
            for (int x = 0; x < size_; ++x) {
                //Only consider pieces of the player who is about to move
                if (isPieceWhite(x, y) != nextPlayerIsWhite || board_[y][x] == 00) continue;

                //Try all possible moves for each piece
                for (int newY = 0; newY < size_; ++newY) {
                    for (int newX = 0; newX < size_; ++newX) {
                        if (isMoveLegal(x, y, newX, newY)) {
                            //Found a legal move, hence it's not a stalemate
                            return false;
                        }
                    }
                }
            }
        }

        std::cout << (nextPlayerIsWhite ? "White" : "Black") << " has no legal moves available: Stalemate." << std::endl;
        return true; //No legal moves available and not in check: it's a stalemate
    }
    
    void pawnPromotion(int x, int y) {
        // Ensure the pawn is on the promotion rank
        if ((board_[y][x] == 01 && y == 0) || (board_[y][x] == 11 && y == 7)) {
            std::string newPiece;
            std::cout << "Pawn promotion! Choose a new piece (Q, R, B, N): ";
            std::cin >> newPiece;

            // Convert input to upper case if necessary
            std::transform(newPiece.begin(), newPiece.end(), newPiece.begin(), ::toupper);

            // Validate input and assign corresponding piece
            if (newPiece == "Q") {
                board_[y][x] = (board_[y][x] == 01) ? 05 : 15; // White Queen or Black Queen
            } else if (newPiece == "R") {
                board_[y][x] = (board_[y][x] == 01) ? 04 : 14; // White Rook or Black Rook
            } else if (newPiece == "B") {
                board_[y][x] = (board_[y][x] == 01) ? 03 : 13; // White Bishop or Black Bishop
            } else if (newPiece == "N") {
                board_[y][x] = (board_[y][x] == 01) ? 02 : 12; // White Knight or Black Knight
            } else {
                std::cout << "Invalid choice. Defaulting to Queen." << std::endl;
                board_[y][x] = (board_[y][x] == 01) ? 05 : 15; // Default to Queen if invalid input
            }

            std::cout << "Pawn has been promoted!" << std::endl;
        } else {
            std::cout << "No pawn promotion needed at this location." << std::endl;
        }
    }

};
#endif