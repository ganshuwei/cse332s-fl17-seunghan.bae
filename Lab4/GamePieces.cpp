// GamePieces.cpp
// Seunghan Bae (seunghan.bae@wustl.edu)
// (Lab 4) source file for game pieces
//

#include "stdafx.h"
#include "GamePieces.h"

using namespace std;

// converts the color enum into string
// p: piece_color enum value
string enumToString(piece_color p)
{
	if (p == BLACK)
	{
		return "black";
	}
	else if (p == WHITE)
	{
		return "white";
	}
	else if (p == RED)
	{
		return "red";
	}
	else if (p == BLUE)
	{
		return "blue";
	}
	else if (p == NO_COLOR)
	{
		return "no_color";
	}
	else
	{
		return "invalid_color";
	}
}

// converts the string into color enum
// s: C++ style string containing color information
piece_color stringToEnum(string s)
{
	if (s == "black")
	{
		return piece_color::BLACK;
	}
	else if (s == "white")
	{
		return piece_color::WHITE;
	}
	else if (s == "red")
	{
		return piece_color::RED;
	}
	else if (s == "blue")
	{
		return piece_color::BLUE;
	}
	else if (s == " " | s == "\t" | s == "no_color")
	{
		return piece_color::NO_COLOR;
	}
	else
	{
		return piece_color::INVALID;
	}
}

// color: color of the piece
// name: name of the piece
// display: shape of the piece
game_pieces::game_pieces(piece_color color, string name, string display) : color_(color), name_(name), display_(display)
{
}
