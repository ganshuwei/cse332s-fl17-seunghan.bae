// GameBoard.cpp
// Seunghan Bae (seunghan.bae@wustl.edu)
// (Lab 1) source file for game board
//

#include "stdafx.h"
#include "Lab1.h"
#include "GameBoard.h"
#include <iostream>
#include <sstream>

using namespace std;

// reads board dimension from the input file
// ifs: input file stream for the input file
// width: unsigned int to store the board's width
// height: unsigned int to store the board's height
int readDimension(ifstream & ifs, unsigned int & width, unsigned int & height)
{
	string s;
	if (getline(ifs, s))
	{
		istringstream iss(s);
		if ((iss >> width) && (iss >> height)) // if correct height and width values are extracted
		{
			return SUCCESS;
		}
		else
		{
			return CANNOT_EXTRACT_DIM;
		}
	}
	else // if no line could be read from the input file stream
	{
		return CANNOT_READ_LINE;
	}
}

// reads board pieces from the input file
// ifs: input file stream for the input file
// v: vector of game_pieces objects
// width: width of the board
// height: height of the board
int readPieces(ifstream & ifs, vector<game_pieces> & v, unsigned int width, unsigned int height)
{
	string s;
	unsigned int readSuccess = 0; // number of game_pieces successfully extracted
	while (getline(ifs, s)) // while there is any line to read
	{
		istringstream iss(s);
		string color, name, display;
		unsigned int x, y;
		if ((iss >> color) && (iss >> name) && (iss >> display) && (iss >> x) && (iss >> y)) // if all 5 values are successfully extracted
		{
			toLowerCase(color);
			piece_color pColor = stringToEnum(color);
			if ((pColor != INVALID) && (x < width) && (y < height)) // if valid game_pieces was extracted
			{
				unsigned int index = width * y + x;
				v[index].color_ = pColor;
				v[index].name_ = name;
				v[index].display_ = display;
				++readSuccess;
			}
		}
	}

	if (readSuccess > 0) // if there is more than one valid game_pieces extracted
	{
		return SUCCESS;
	}
	else
	{
		return NO_PIECE_DEF;
	}
}

// prints the board and its pieces out
// v: vector of game_pieces objects
// width: width of the board
// height: height of the board
int printPieces(const vector<game_pieces> & v, unsigned int width, unsigned int height)
{
	if (v.size() == width * height) // if vector size matches the board dimensions
	{
		for (int y = height - 1; y >= 0; --y)
		{
			for (unsigned int x = 0; x < width; ++x)
			{
				cout << v[width * y + x].display_;
			}
			cout << endl;
		}

		return SUCCESS;
	}
	else
	{
		return VECTOR_DIM_MISMATCH;
	}
}

// prints the neighbors of each game_pieces printed
// v: vector of game_pieces objects
// width: width of the board
// height: height of the board
int printNeighbor(const vector<game_pieces> & v, unsigned int width, unsigned int height)
{
	cout << endl;
	
	// iterate through the entire board
	for (unsigned int x = 0; x < width; ++x)
	{
		for (unsigned int y = 0; y < height; ++y)
		{
			unsigned int index = width * y + x;
			if (v[index].display_ != " ") // if there is a piece drawn
			{
				// print itself
				cout << x << "," << y << " " << enumToString(v[index].color_) << " " << v[index].name_ << ": ";
				
				// east
				if ((width * y + (x + 1) < v.size()) && (x + 1 < width))
				{
					if (v[width * y + (x + 1)].display_ != " ")
					{
						cout << (x + 1) << "," << y << " " << enumToString(v[width * y + (x + 1)].color_) << " " << v[width * y + (x + 1)].name_ << "; ";
					}
				}
				// northeast
				if ((width * (y + 1) + (x + 1) < v.size()) && (y + 1 < height) && (x + 1 < width))
				{
					if (v[width * (y + 1) + (x + 1)].display_ != " ")
					{
						cout << (x + 1) << "," << (y + 1) << " " << enumToString(v[width * (y + 1) + (x + 1)].color_) << " " << v[width * (y + 1) + (x + 1)].name_ << "; ";
					}
				}
				// north
				if ((width * (y + 1) + x < v.size()) && (y + 1 < height))
				{
					if (v[width * (y + 1) + x].display_ != " ")
					{
						cout << x << "," << (y + 1) << " " << enumToString(v[width * (y + 1) + x].color_) << " " << v[width * (y + 1) + x].name_ << "; ";
					}
				}
				// northwest
				if ((width * (y + 1) + (x - 1) < v.size()) && (y + 1 < height) && (x >= 1))
				{
					if (v[width * (y + 1) + (x - 1)].display_ != " ")
					{
						cout << (x - 1) << "," << (y + 1) << " " << enumToString(v[width * (y + 1) + (x - 1)].color_) << " " << v[width * (y + 1) + (x - 1)].name_ << "; ";
					}
				}
				// west
				if ((width * y + (x - 1) < v.size()) && (x >= 1))
				{
					if (v[width * y + (x - 1)].display_ != " ")
					{
						cout << (x - 1) << "," << y << " " << enumToString(v[width * y + (x - 1)].color_) << " " << v[width * y + (x - 1)].name_ << "; ";
					}
				}
				// southwest
				if ((width * (y - 1) + (x - 1) < v.size()) && (y >= 1) && (x >= 1))
				{
					if (v[width * (y - 1) + (x - 1)].display_ != " ")
					{
						cout << (x - 1) << "," << (y - 1) << " " << enumToString(v[width * (y - 1) + (x - 1)].color_) << " " << v[width * (y - 1) + (x - 1)].name_ << "; ";
					}
				}
				// south
				if ((width * (y - 1) + x < v.size()) && (y >= 1))
				{
					if (v[width * (y - 1) + x].display_ != " ")
					{
						cout << x << "," << (y - 1) << " " << enumToString(v[width * (y - 1) + x].color_) << " " << v[width * (y - 1) + x].name_ << "; ";
					}
				}
				// southeast
				if ((width * (y - 1) + (x + 1) < v.size()) && (y >= 1) && (x + 1 < width))
				{
					if (v[width * (y - 1) + (x + 1)].display_ != " ")
					{
						cout << (x + 1) << "," << (y - 1) << " " << enumToString(v[width * (y - 1) + (x + 1)].color_) << " " << v[width * (y - 1) + (x + 1)].name_ << "; ";
					}
				}

				cout << endl;
			}
		}
	}

	return SUCCESS;
}
