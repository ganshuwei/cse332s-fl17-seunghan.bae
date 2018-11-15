// GamePieces.h
// Seunghan Bae (seunghan.bae@wustl.edu)
// (Lab 1) header file for game pieces
//

#ifndef GAME_PIECES_H
#define GAME_PIECES_H

#include <string>

enum piece_color { BLACK, WHITE, RED, BLUE, NO_COLOR, INVALID };

std::string enumToString(piece_color);

piece_color stringToEnum(std::string);

struct game_pieces {
	game_pieces(piece_color color, std::string name, std::string display);

	piece_color color_;
	std::string name_;
	std::string display_;
};

#endif /* GAME_PIECES_H */
