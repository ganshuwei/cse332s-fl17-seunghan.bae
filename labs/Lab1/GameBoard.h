// GameBoard.h
// Seunghan Bae (seunghan.bae@wustl.edu)
// (Lab 1) header file for game board
//

#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include "GamePieces.h"
#include <vector>
#include <fstream>

int readDimension(std::ifstream &, unsigned int &, unsigned int &);

int readPieces(std::ifstream &, std::vector<game_pieces> &, unsigned int, unsigned int);

int printPieces(const std::vector<game_pieces> &, unsigned int, unsigned int);

int printNeighbor(const std::vector<game_pieces> &, unsigned int, unsigned int);

#endif /* GAME_BOARD_H */
