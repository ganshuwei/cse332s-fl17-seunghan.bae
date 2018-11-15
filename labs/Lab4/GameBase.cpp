// GameBase.cpp
// Seunghan Bae (seunghan.bae@wustl.edu)
// (Lab 4) source file for the GameBase class
//

#include "stdafx.h"
#include "TicTacToe.h"
#include "Gomoku.h"
#include "Sudoku.h"
#include "UltimateTicTacToe.h"
#include <sstream>

using namespace std;

// constructor for the GameBase class
// width_: width of the board
// height_: height of the board
// pieceCount_: number of game_pieces in the board
// gpVtr_: vector of game_pieces
// turn_: true if it is Player O/White Stone's turn
// displayLength_: maximum length of display string
GameBase::GameBase(unsigned int width, unsigned int height) : width_(width), height_(height), pieceCount_(width * height), turn_(true), turnCount_(0), displayLength_(1)
{
	for (unsigned int i = 0; i < pieceCount_; ++i)
	{
		game_pieces gp(NO_COLOR, "", " ");
		gpVtr_.push_back(gp);
	}
}

// copy constructor for the GameBase class
GameBase::GameBase(const GameBase & g) : width_(g.width_), height_(g.height_), pieceCount_(g.width_ * g.height_), turn_(g.turn_), turnCount_(g.turnCount_), displayLength_(g.displayLength_)
{
	for (unsigned int i = 0; i < g.gpVtr_.size(); ++i)
	{
		gpVtr_.push_back(g.gpVtr_[i]);
	}
}

// move constructor for the GameBase class
GameBase::GameBase(GameBase && g) : width_(g.width_), height_(g.height_), pieceCount_(g.width_ * g.height_), turn_(g.turn_), turnCount_(g.turnCount_), displayLength_(g.displayLength_)
{
	for (unsigned int i = 0; i < g.gpVtr_.size(); ++i)
	{
		gpVtr_.push_back(g.gpVtr_[i]);
	}
	for (unsigned int i = 0; i < g.gpVtr_.size(); ++i)
	{
		g.gpVtr_.pop_back();
	}

	g.width_ = 0;
	g.height_ = 0;
	g.pieceCount_ = 0;
	g.turnCount_ = 0;
	g.displayLength_ = 0;
}

/*// destructor for the GameBase class
GameBase::~GameBase()
{
	for (unsigned int i = 0; i < gpVtr_.size(); ++i)
	{
		gpVtr_.pop_back();
	}
}

// copy-assignment operator for the GameBase class
GameBase & GameBase::operator=(const GameBase & g)
{
	if (&g != this)
	{
		width_ = g.width_;
		height_ = g.height_;
		pieceCount_ = g.pieceCount_;
		turn_ = g.turn_;
		turnCount_ = g.turnCount_;
		displayLength_ = g.displayLength_;

		for (unsigned int i = 0; i < gpVtr_.size(); ++i)
		{
			gpVtr_.pop_back();
		}
		for (unsigned int i = 0; i < g.gpVtr_.size(); ++i)
		{
			gpVtr_.push_back(g.gpVtr_[i]);
		}
	}
	
	return *this;
}

// move-assignment operator for the GameBase class
GameBase & GameBase::operator=(GameBase && g)
{
	if (&g != this)
	{
		width_ = g.width_;
		height_ = g.height_;
		pieceCount_ = g.pieceCount_;
		turn_ = g.turn_;
		turnCount_ = g.turnCount_;
		displayLength_ = g.displayLength_;
		g.width_ = 0;
		g.height_ = 0;
		g.pieceCount_ = 0;
		g.turnCount_ = 0;
		g.displayLength_ = 1;

		for (unsigned int i = 0; i < gpVtr_.size(); ++i)
		{
			gpVtr_.pop_back();
		}
		for (unsigned int i = 0; i < g.gpVtr_.size(); ++i)
		{
			gpVtr_.push_back(g.gpVtr_[i]);
		}
		for (unsigned int i = 0; i < g.gpVtr_.size(); ++i)
		{
			g.gpVtr_.pop_back();
		}
	}
	
	return *this;
}*/

// prompts player to type either 'quit' or 'x,y'
// n1: x-coordinate of the game_piece
// n2: y-coordinate of the game_piece
void GameBase::prompt(unsigned int & n1, unsigned int & n2)
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
			for (unsigned int i = 0; i < s.length(); ++i)
			{
				if (s[i] == ',')
				{
					s[i] = ' ';
					break;
				}
			}

			istringstream iss(s);
			if ((iss >> n1) && (iss >> n2))
			{
				valid = true;
				returnVal = SUCCESS;
			}
		}
	}

	throw returnVal;
}

// plays the game
int GameBase::play()
{
	print();
	cout << endl;

	int result = -1;

	while (result < 0) // repeats until the game ends (quit, draw, or win)
	{
		if (turn() == SUCCESS)
		{
			++turnCount_;
			if (done())
			{
				result = SUCCESS;
			}
			else
			{
				if (draw())
				{
					cout << "game ended draw: " << turnCount_ << " turn(s) played" << endl;
					result = GAME_ENDED_DRAW;
				}
			}
		}
		else
		{
			cout << "user quit: " << turnCount_ << " turn(s) played" << endl;
			result = USER_QUIT;
		}

	}
	return result;
}

// initializes the game by checking argc and argv
// argc
// argv
void GameBase::start(int argc, char * argv[])
{
	if (sharedPtr_ == nullptr)
	{
		if (argc == EXPECTED_ARG_NUM)
		{
			if (strcmp(argv[GAME], "TicTacToe") == 0)
			{
				sharedPtr_ = make_shared<TicTacToe>();
			}
			else if (strcmp(argv[GAME], "Gomoku") == 0)
			{
				sharedPtr_ = make_shared<Gomoku>();
			}
			else if (strcmp(argv[GAME], "Sudoku") == 0)
			{
				sharedPtr_ = make_shared<Sudoku>();
			}
			else if (strcmp(argv[GAME], "UltimateTicTacToe") == 0)
			{
				sharedPtr_ = make_shared<UltimateTicTacToe>();
			}
			else
			{
				throw WRONG_GAME_NAME;
				return;
			}
		}
		else
		{
			throw WRONG_ARG_NUM;
			return;
		}
	}
	else
	{
		throw PTR_NOT_NULL;
		return;
	}
}

// returns a shared smart pointer to the GameBase class
shared_ptr<GameBase> GameBase::instance()
{
	if (sharedPtr_ == nullptr)
	{
		throw NULL_PTR_EXCEPTION;
	}
	
	return sharedPtr_;
}

shared_ptr<GameBase> GameBase::sharedPtr_ = nullptr;
