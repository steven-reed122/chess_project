// This file contains the input functions for the chess game.
// The input functions are used to get the input from the user.
// Written on 03/19/2024

#ifndef INPUT_HPP
#define INPUT_HPP

# include <iostream>
# include <string>
# include <vector>

std::string getMovingPiece() {
    std::string move;
    std::cout << "Enter the piece you want to move: (ex. a2)";
    std::cin >> move;
    return move;
}

std::string getNewPosition() {
    std::string move;
    std::cout << "Enter the new position: (ex. a4)";
    std::cin >> move;
    return move;
}


#endif