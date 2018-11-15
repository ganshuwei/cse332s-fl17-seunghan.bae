// Lab1.cpp
// Seunghan Bae (seunghan.bae@wustl.edu)
// (Lab 1) main application source file
//

#include "stdafx.h"
#include "Lab1.h"
#include "GameBoard.h"
#include <iostream>

using namespace std;

int main(int argc, char * argv[])
{
	// check if expected number of command line arguments are given
	if (argc == EXPECTED_ARG_NUM)
	{
		ifstream ifs(argv[INPUT_FILE]);
		if (ifs.is_open())
		{
			// declare height and width variables,
			// read each line of the input file until board dimensions are extracted
			unsigned int width, height;
			int returnVal = readDimension(ifs, width, height);
			while (returnVal == CANNOT_EXTRACT_DIM)
			{
				returnVal = readDimension(ifs, width, height);
			}

			if (returnVal == SUCCESS) // if board dimensions are successfully extracted
			{
				// declare a vector of game_pieces,
				// fill the vector with empty game_pieces
				vector<game_pieces> gameVtr;
				for (unsigned int i = 0; i < width * height; ++i)
				{
					game_pieces gp(NO_COLOR, "", " ");
					gameVtr.push_back(gp);
				}

				// read each line of the input file and extract piece definitions
				int returnVal2 = readPieces(ifs, gameVtr, width, height);
				if (returnVal2 == SUCCESS) // if at least one piece definition was extracted
				{
					// close the input file stream,
					// print the board out
					ifs.close();
					int returnVal3 = printPieces(gameVtr, width, height);

					// Extra Credit
					if (returnVal3 == SUCCESS)
					{
						return printNeighbor(gameVtr, width, height);
					}
					else
					{
						cout << "error: vector size and board dimensions do not match" << endl;
						return returnVal3;
					}
				}
				else
				{
					ifs.close();
					cout << "error: cannot find any piece definitions from '" << argv[INPUT_FILE] << "'" << endl;
					return returnVal2;
				}
			}
			else
			{
				ifs.close();
				cout << "error: cannot extract board dimensions from '" << argv[INPUT_FILE] << "'" << endl;
				return returnVal;
			}
		}
		else
		{
			cout << "error: cannot open '" << argv[INPUT_FILE] << "'" << endl;
			return CANNOT_OPEN_FILE;
		}
	}
	else
	{
		return usageMsg(argv[PROGRAM], "<input_file_name>");
	}
}

// converts the string into all lower cases
// s: C++ style string to be converted
void toLowerCase(string & s)
{
	for (size_t i = 0; i < s.size(); ++i)
	{
		if ((s[i] >= 0x41) && (s[i] <= 0x5a)) // if A-Z
		{
			s[i] = s[i] + 0x20;
		}
	}
}

// prints out the usage message
// c1: name of the program (argv[0])
// c2: first command line argument, which is the input file name (argv[1])
int usageMsg(char * c1, char * c2)
{
	cout << "usage: " << c1 << " " << c2 << endl;
	return WRONG_ARG_NUM;
}
