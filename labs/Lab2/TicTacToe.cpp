// TicTacToe.cpp
// Seunghan Bae (seunghan.bae@wustl.edu)
// (Lab 2) source file for TicTacToeGame class
//

#include "stdafx.h"
#include "TicTacToe.h"
#include <sstream>

using namespace std;

// prints out the board and game pieces
// os: ostream used for printing
// game: tic-tac-toe game to be printed
ostream & operator<<(ostream & os, const TicTacToeGame & game)
{
	for (int y = game.height_ - 1; y >= 0; --y)
	{
		os << y;
		for (unsigned int x = 0; x < game.width_; ++x)
		{
			os << game.gpVtr_[game.width_ * y + x].display_ << " ";
		}
		os << endl;
	}
	os << " ";
	for (unsigned int x = 0; x < game.width_; ++x)
	{
		os << x << " ";
	}

	return os;
}

// default constructor for the TicTacToeGame class
// width_: width of the board
// height_: height of the board
// oTurn_: true if it is Player O's turn
// autoP_: true if auto_player is enabled
// gpVtr_: vector of 25 game_pieces objects
TicTacToeGame::TicTacToeGame() : width_(5), height_(5), oTurn_(true), autoP_(false)
{
	for (int i = 0; i < 25; ++i)
	{
		game_pieces gp(NO_COLOR, "", " ");
		gpVtr_.push_back(gp);
	}
}

// copy constructor for the TicTacToeGame class
TicTacToeGame::TicTacToeGame(const TicTacToeGame & game) : width_(game.width_), height_(game.height_), oTurn_(game.oTurn_), autoP_(game.autoP_)
{
	for (int i = 0; i < 25; ++i)
	{
		gpVtr_.push_back(game.gpVtr_[i]);
	}
}

// constructor made for extra credit portion
TicTacToeGame::TicTacToeGame(bool autoP) : width_(5), height_(5), oTurn_(true), autoP_(autoP)
{
	for (int i = 0; i < 25; ++i)
	{
		game_pieces gp(NO_COLOR, "", " ");
		gpVtr_.push_back(gp);
	}
}

// returns true when either of the players won
bool TicTacToeGame::done()
{
	bool row1 = (gpVtr_[6].display_ != " ") && (gpVtr_[6].display_ == gpVtr_[7].display_) && (gpVtr_[7].display_ == gpVtr_[8].display_);
	bool row2 = (gpVtr_[11].display_ != " ") && (gpVtr_[11].display_ == gpVtr_[12].display_) && (gpVtr_[12].display_ == gpVtr_[13].display_);
	bool row3 = (gpVtr_[16].display_ != " ") && (gpVtr_[16].display_ == gpVtr_[17].display_) && (gpVtr_[17].display_ == gpVtr_[18].display_);
	bool col1 = (gpVtr_[6].display_ != " ") && (gpVtr_[6].display_ == gpVtr_[11].display_) && (gpVtr_[11].display_ == gpVtr_[16].display_);
	bool col2 = (gpVtr_[7].display_ != " ") && (gpVtr_[7].display_ == gpVtr_[12].display_) && (gpVtr_[12].display_ == gpVtr_[17].display_);
	bool col3 = (gpVtr_[8].display_ != " ") && (gpVtr_[8].display_ == gpVtr_[13].display_) && (gpVtr_[13].display_ == gpVtr_[18].display_);
	bool diag1 = (gpVtr_[6].display_ != " ") && (gpVtr_[6].display_ == gpVtr_[12].display_) && (gpVtr_[12].display_ == gpVtr_[18].display_);
	bool diag2 = (gpVtr_[8].display_ != " ") && (gpVtr_[8].display_ == gpVtr_[12].display_) && (gpVtr_[12].display_ == gpVtr_[16].display_);

	return (row1 || row2 || row3 || col1 || col2 || col3 || diag1 || diag2);
}

// returns true when the game ended draw
bool TicTacToeGame::draw()
{
	bool noMove = true;
	for (int x = X_BEG; x <= X_END; ++x)
	{
		for (int y = Y_BEG; y <= Y_END; ++y)
		{
			if (gpVtr_[width_ * y + x].display_ == " ")
			{
				noMove = false;
				break;
			}
		}
	}

	return (noMove && !done());
}

// prompts player to type either 'quit' or 'x,y'
// n1: x-coordinate of the game piece
// n2: y-coordinate of the game piece
int TicTacToeGame::prompt(unsigned int & n1, unsigned int & n2)
{
	bool valid = false;
	int returnVal;

	while (!valid) // repeats until valid string is received
	{
		cout << "type 'quit' or 'x,y': ";
		string s;
		cin >> s;

		if (s == "quit")
		{
			valid = true;
			returnVal = USER_QUIT;
		}
		else
		{
			if (s.length() == 3 && s[1] == ',') // if the string is formatted 'x,y'
			{
				s[1] = ' ';
				istringstream iss(s);
				if ((iss >> n1) && (iss >> n2))
				{
					valid = true;
					returnVal = SUCCESS;
				}
			}
		}
	}

	return returnVal;
}

// receives input for each player's turn and prints out the board
int TicTacToeGame::turn()
{
	oTurn_ = !oTurn_; // switch turn
	unsigned int x, y;
	bool valid = false;

	if (autoP_ && oTurn_) // extra credit
	{
		int index = auto_player();
		x = index % width_;
		y = index / width_;

		gpVtr_[index].color_ = RED;
		gpVtr_[index].display_ = "O";
		gpVtr_[index].name_ = "Player O";
	}
	else
	{
		while (!valid) // repeats until valid string is received
		{
			if (prompt(x, y) == SUCCESS)
			{
				if (x >= X_BEG && x <= X_END && y >= Y_BEG && y <= Y_END) // if x,y is within valid range
				{
					if (gpVtr_[width_ * y + x].display_ == " ") // if the coordinate is empty
					{
						gpVtr_[width_ * y + x].color_ = oTurn_ ? RED : BLUE;
						gpVtr_[width_ * y + x].display_ = oTurn_ ? "O" : "X";
						gpVtr_[width_ * y + x].name_ = oTurn_ ? "Player O" : "Player X";
						valid = true;
					}
				}
			}
			else
			{
				valid = true;
				return USER_QUIT;
			}
		}
	}
	
	cout << *this << endl;
	cout << endl;
	cout << gpVtr_[width_ * y + x].name_ << ": " << x << "," << y << endl;
	cout << endl;
	return SUCCESS;
}

// plays the game
int TicTacToeGame::play()
{
	cout << *this << endl;
	cout << endl;

	int result = -1;
	int turnCount = 0;

	while (result < 0) // repeats until the game ends (quit, draw, or win)
	{
		if (turn() == SUCCESS)
		{
			++turnCount;
			if (done())
			{
				string player = oTurn_ ? "O" : "X";
				cout << "Player " << player << " wins" << endl;
				result = SUCCESS;
			}
			else
			{
				if (draw())
				{
					cout << "game ended draw: " << turnCount << " turn(s) played" << endl;
					result = GAME_ENDED_DRAW;
				}
			}
		}
		else
		{
			cout << "user quit: " << turnCount << " turn(s) played" << endl;
			result = USER_QUIT;
		}

	}
	return result;
}

// determines auto_player's next move and returns the vector index of the selection
unsigned int TicTacToeGame::auto_player()
{
	cout << "auto_player's turn:" << endl;
	unsigned int lines[8][3] = { { 6, 7, 8 }, { 11, 12, 13 }, { 16, 17, 18 }, { 6, 11, 16 }, { 7, 12, 17 }, { 8, 13, 18 }, { 6, 12, 18 }, { 8, 12, 16 } }; // all 8 possible lines within the board
	int score[25] = { 0 }; // array of each cell's "priority score" (begins with 0)
	int maxScore = 0;

	// find out how each of the 8 lines are filled with pieces
	for (unsigned int i = 0; i < 8; ++i)
	{
		int lineSum = 0;
		for (unsigned int j = 0; j < 3; ++j)
		{
			if (gpVtr_[lines[i][j]].display_ == "X")
			{
				lineSum += 2;
			}
			else if (gpVtr_[lines[i][j]].display_ == "O")
			{
				lineSum += 3;
			}
			else // if empty
			{
				lineSum += 0;
			}
		}

		if (lineSum == 6) // if two 'O's in the line
		{
			for (unsigned int j = 0; j < 3; ++j)
			{
				score[lines[i][j]] += 100;
			}
		}
		else if (lineSum == 5) // if one 'X' and one 'O' in the line
		{
			for (unsigned int j = 0; j < 3; ++j)
			{
				score[lines[i][j]] += 1;
			}
		}
		else if (lineSum == 4) // if two 'X's in the line
		{
			for (unsigned int j = 0; j < 3; ++j)
			{
				score[lines[i][j]] += 75;
			}
		}
		else if (lineSum == 3) // if one 'O' in the line
		{
			for (unsigned int j = 0; j < 3; ++j)
			{
				score[lines[i][j]] += 20;
			}
		}
		else if (lineSum == 2) // if one 'X' in one line
		{
			for (unsigned int j = 0; j < 3; ++j)
			{
				score[lines[i][j]] += 25;
			}
		}
		else // if the line is empty
		{
			for (unsigned int j = 0; j < 3; ++j)
			{
				score[lines[i][j]] += 10;
			}
		}
	}
	
	// get the cell with maximum "priority score"
	unsigned int index = 0;
	for (unsigned int x = 1; x <= 3; ++x)
	{
		for (unsigned int y = 1; y <= 3; ++y)
		{
			if (gpVtr_[width_ * y + x].display_ != " ") // if the cell is already filled
			{
				score[5 * y + x] = 0;
			}
			if (score[5 * y + x] >= maxScore)
			{
				maxScore = score[5 * y + x];
				index = 5 * y + x;
			}
		}
	}

	return index;
}