// GameClasses.cpp
// Seunghan Bae (seunghan.bae@wustl.edu)
// (Lab 3) source file for game classes
//

#include "stdafx.h"
#include "GameClasses.h"
#include <sstream>

using namespace std;

// constructor for the GameBase class
// width_: width of the board
// height_: height of the board
// pieceCount_: number of game_pieces in the board
// gpVtr_: vector of game_pieces
// turn_: true if it is Player O/White Stone's turn
// displayLength_: maximum length of display string
GameBase::GameBase(unsigned int width, unsigned int height) : width_(width), height_(width), pieceCount_(width_ * height_), turn_(true), displayLength_(1)
{
	for (unsigned int i = 0; i < pieceCount_; ++i)
	{
		game_pieces gp(NO_COLOR, "", " ");
		gpVtr_.push_back(gp);
	}
}

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
	int turnCount = 0;

	while (result < 0) // repeats until the game ends (quit, draw, or win)
	{
		if (turn() == SUCCESS)
		{
			++turnCount;
			if (done())
			{
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

// initializes the game by checking argc and argv
// argc
// argv
GameBase * GameBase::start(int argc, char * argv[])
{
	if (argc == EXPECTED_ARG_NUM && strcmp(argv[GAME], "TicTacToe") == 0)
	{
		return new TicTacToe;
	}
	else if (argc == EXPECTED_ARG_NUM && strcmp(argv[GAME], "Gomoku") == 0)
	{
		return new Gomoku;
	}
	else if (argc == ONE_MORE_ARG && strcmp(argv[GAME], "Gomoku") == 0 && atoi(argv[BOARD_DIM]) >= 1)
	{
		return new Gomoku(atoi(argv[BOARD_DIM]), GMK_CONNECT);
	}
	else if (argc == TWO_MORE_ARG && strcmp(argv[GAME], "Gomoku") == 0 && atoi(argv[BOARD_DIM]) >= 1 && atoi(argv[CONNECT]) >= 3)
	{
		return new Gomoku(atoi(argv[BOARD_DIM]), atoi(argv[CONNECT]));
	}
	else
	{
		return 0;
	}
}

// prints out the TicTacToe game
// os: ostream used for printing
// ttt: TicTacToe game to be printed
ostream & operator<<(ostream & os, const TicTacToe & ttt)
{
	for (int y = ttt.height_ - 1; y >= 0; --y)
	{
		os.width(1);
		os << y;
		for (unsigned int x = 0; x < ttt.width_; ++x)
		{
			os.width(1);
			os << " ";
			os.width(ttt.displayLength_);
			os << right << ttt.gpVtr_[ttt.width_ * y + x].display_;
		}
		os << endl;
	}
	os.width(1);
	os << " ";
	for (unsigned int x = 0; x < ttt.width_; ++x)
	{
		os.width(1);
		os << " ";
		os.width(ttt.displayLength_);
		os << right << x;
	}

	return os;
}

// default constructor for the TicTacToe class
TicTacToe::TicTacToe() : GameBase(TTT_DIM, TTT_DIM)
{
}

// prints out the TicTacToe game
void TicTacToe::print()
{
	cout << *this << endl;
}

// returns true when either of the players won
bool TicTacToe::done()
{
	bool row1 = (gpVtr_[6].display_ != " ") && (gpVtr_[6].display_ == gpVtr_[7].display_) && (gpVtr_[7].display_ == gpVtr_[8].display_);
	bool row2 = (gpVtr_[11].display_ != " ") && (gpVtr_[11].display_ == gpVtr_[12].display_) && (gpVtr_[12].display_ == gpVtr_[13].display_);
	bool row3 = (gpVtr_[16].display_ != " ") && (gpVtr_[16].display_ == gpVtr_[17].display_) && (gpVtr_[17].display_ == gpVtr_[18].display_);
	bool col1 = (gpVtr_[6].display_ != " ") && (gpVtr_[6].display_ == gpVtr_[11].display_) && (gpVtr_[11].display_ == gpVtr_[16].display_);
	bool col2 = (gpVtr_[7].display_ != " ") && (gpVtr_[7].display_ == gpVtr_[12].display_) && (gpVtr_[12].display_ == gpVtr_[17].display_);
	bool col3 = (gpVtr_[8].display_ != " ") && (gpVtr_[8].display_ == gpVtr_[13].display_) && (gpVtr_[13].display_ == gpVtr_[18].display_);
	bool diag1 = (gpVtr_[6].display_ != " ") && (gpVtr_[6].display_ == gpVtr_[12].display_) && (gpVtr_[12].display_ == gpVtr_[18].display_);
	bool diag2 = (gpVtr_[8].display_ != " ") && (gpVtr_[8].display_ == gpVtr_[12].display_) && (gpVtr_[12].display_ == gpVtr_[16].display_);

	bool result = (row1 || row2 || row3 || col1 || col2 || col3 || diag1 || diag2);
	if (result)
	{
		string player = turn_ ? "O" : "X";
		cout << "Player " << player << " wins" << endl;
	}
	return result;
}

// returns true when the game ended draw
bool TicTacToe::draw()
{
	bool noMove = true;
	for (unsigned int x = 1; x < (width_ - 1); ++x)
	{
		for (unsigned int y = 1; y < (height_ - 1); ++y)
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

// receives input for each player's turn and prints out the board
int TicTacToe::turn()
{
	turn_ = !turn_; // switch turn
	unsigned int x, y;
	bool valid = false;
	int returnVal = -1;

	while (!valid) // repeats until valid string is received
	{
		try
		{
			prompt(x, y);
		}
		catch (int & i)
		{
			if (i == SUCCESS)
			{
				if (x >= 1 && x < (width_ - 1) && y >= 1 && y < (height_ - 1)) // if x,y is within valid range
				{
					if (gpVtr_[width_ * y + x].display_ == " ") // if the coordinate is empty
					{
						gpVtr_[width_ * y + x].color_ = turn_ ? RED : BLUE;
						gpVtr_[width_ * y + x].display_ = turn_ ? "O" : "X";
						gpVtr_[width_ * y + x].name_ = turn_ ? "Player O" : "Player X";
						if (displayLength_ < gpVtr_[width_ * y + x].display_.size())
						{
							displayLength_ = gpVtr_[width_ * y + x].display_.size();
						}
						valid = true;
						returnVal = i;
					}
				}
			}
			else // if (i == USER_QUIT)
			{
				valid = true;
				returnVal = i;
			}
		}
	}

	if (returnVal == SUCCESS)
	{
		print();
		cout << endl;
		cout << gpVtr_[width_ * y + x].name_ << ": ";
		for (unsigned int xx = 1; xx < (width_ - 1); ++xx)
		{
			for (unsigned int yy = 1; yy < (height_ - 1); ++yy)
			{
				if (gpVtr_[width_ * yy + xx].name_ == gpVtr_[width_ * y + x].name_)
				{
					cout << xx << "," << yy << "; ";
				}
			}
		}
		cout << endl;
		cout << endl;
	}

	return returnVal;
}

// prints out the Gomoku game
// os: ostream used for printing
// gmk: Gomoku game to be printed
ostream & operator<<(ostream & os, const Gomoku & gmk)
{
	unsigned int numCharLength = (gmk.width_ > 9) ? 2 : 1;

	for (int y = gmk.height_ - 1; y >= 0; --y)
	{
		os.width(numCharLength);
		os << right << (y + 1);
		for (unsigned int x = 0; x < gmk.width_; ++x)
		{
			os.width(1);
			os << " ";
			os.width((gmk.displayLength_ > numCharLength) ? gmk.displayLength_ : numCharLength);
			os << right << gmk.gpVtr_[gmk.width_ * y + x].display_;
		}
		os << endl;
	}
	os.width(numCharLength);
	os << right << "X";
	for (unsigned int x = 0; x < gmk.width_; ++x)
	{
		os.width(1);
		os << " ";
		os.width((gmk.displayLength_ > numCharLength) ? gmk.displayLength_ : numCharLength);
		os << right << (x + 1);
	}

	return os;
}

// default constructor for the Gomoku class
Gomoku::Gomoku() : GameBase(GMK_DIM, GMK_DIM), connect_(GMK_CONNECT)
{
}

// extra-credit constructor for the Gomoku class
Gomoku::Gomoku(unsigned int dim, unsigned int connect) : GameBase(dim, dim), connect_(connect)
{
}

// prints out the Gomoku game
void Gomoku::print()
{
	cout << *this << endl;
}

// returns true when either of the players won
bool Gomoku::done()
{
	for (unsigned int x = 0; x < width_; ++x)
	{
		for (unsigned int y = 0; y < height_; ++y)
		{
			if (gpVtr_[width_ * y + x].display_ != " ")
			{
				unsigned int score = 0;
				for (int dir = E; dir <= SE; ++dir)
				{
					unsigned int tempScore = doneCheck(x, y, dir);
					if (tempScore > score)
					{
						score = tempScore;
					}
				}
				if (score >= connect_ - 1)
				{
					string stone = turn_ ? "White" : "Black";
					cout << stone << " Stone wins" << endl;
					return true;
				}
			}
		}
	}
	return false;
}

// checks neighboring game_pieces recursively
// x: x-coordinate of the current game_piece
// y: y-coordinate of the current game_piece
// dir: direction of the next game_piece to be checked
unsigned int Gomoku::doneCheck(unsigned int x, unsigned int y, int & dir)
{
	if (dir == E)
	{
		if ((width_ * y + (x + 1) < gpVtr_.size()) && (x + 1 < width_))
		{
			if (gpVtr_[width_ * y + (x + 1)].display_ == gpVtr_[width_ * y + x].display_)
			{
				return (1 + doneCheck(x + 1, y, dir));
			}
		}
		return 0;
	}
	else if (dir == NE)
	{
		if ((width_ * (y + 1) + (x + 1) < gpVtr_.size()) && (y + 1 < height_) && (x + 1 < width_))
		{
			if (gpVtr_[width_ * (y + 1) + (x + 1)].display_ == gpVtr_[width_ * y + x].display_)
			{
				return (1 + doneCheck(x + 1, y + 1, dir));
			}
		}
		return 0;
	}
	else if (dir == N)
	{
		if ((width_ * (y + 1) + x < gpVtr_.size()) && (y + 1 < height_))
		{
			if (gpVtr_[width_ * (y + 1) + x].display_ == gpVtr_[width_ * y + x].display_)
			{
				return (1 + doneCheck(x, y + 1, dir));
			}
		}
		return 0;
	}
	else if (dir == NW)
	{
		if ((width_ * (y + 1) + (x - 1) < gpVtr_.size()) && (y + 1 < height_) && (x >= 1))
		{
			if (gpVtr_[width_ * (y + 1) + (x - 1)].display_ == gpVtr_[width_ * y + x].display_)
			{
				return (1 + doneCheck(x - 1, y + 1, dir));
			}
		}
		return 0;
	}
	else if (dir == W)
	{
		if ((width_ * y + (x - 1) < gpVtr_.size()) && (x >= 1))
		{
			if (gpVtr_[width_ * y + (x - 1)].display_ == gpVtr_[width_ * y + x].display_)
			{
				return (1 + doneCheck(x - 1, y, dir));
			}
		}
		return 0;
	}
	else if (dir == SW)
	{
		if ((width_ * (y - 1) + (x - 1) < gpVtr_.size()) && (y >= 1) && (x >= 1))
		{
			if (gpVtr_[width_ * (y - 1) + (x - 1)].display_ == gpVtr_[width_ * y + x].display_)
			{
				return (1 + doneCheck(x - 1, y - 1, dir));
			}
		}
		return 0;
	}
	else if (dir == S)
	{
		if ((width_ * (y - 1) + x < gpVtr_.size()) && (y >= 1))
		{
			if (gpVtr_[width_ * (y - 1) + x].display_ == gpVtr_[width_ * y + x].display_)
			{
				return (1 + doneCheck(x, y - 1, dir));
			}
		}
		return 0;
	}
	else // if (dir == SE)
	{
		if ((width_ * (y - 1) + (x + 1) < gpVtr_.size()) && (y >= 1) && (x + 1 < width_))
		{
			if (gpVtr_[width_ * (y - 1) + (x + 1)].display_ == gpVtr_[width_ * y + x].display_)
			{
				return (1 + doneCheck(x + 1, y - 1, dir));
			}
		}
		return 0;
	}
}

// returns true when the game ended draw
bool Gomoku::draw()
{
	for (unsigned int x = 0; x < width_; ++x)
	{
		for (unsigned int y = 0; y < height_; ++y)
		{
			if (gpVtr_[width_ * y + x].display_ == " ")
			{
				unsigned int score = 0;
				for (int dir = E; dir <= SE; ++dir)
				{
					unsigned int tempScore = doneCheck(x, y, dir);
					if (tempScore > score)
					{
						score = tempScore;
					}
				}
				if (score >= connect_ - 2)
				{
					return false;
				}
			}
		}
	}
	return true;
}

// receives input for each player's turn and prints out the board
int Gomoku::turn()
{
	turn_ = !turn_; // switch turn
	unsigned int x, y;
	bool valid = false;
	int returnVal = -1;

	while (!valid) // repeats until valid string is received
	{
		try
		{
			prompt(x, y);
		}
		catch (int & i)
		{
			if (i == SUCCESS)
			{
				if ((x - 1) < width_ && (y - 1) < height_) // if x,y is within valid range
				{
					if (gpVtr_[width_ * (y - 1) + (x - 1)].display_ == " ") // if the coordinate is empty
					{
						gpVtr_[width_ * (y - 1) + (x - 1)].color_ = turn_ ? WHITE : BLACK;
						gpVtr_[width_ * (y - 1) + (x - 1)].display_ = turn_ ? "W" : "B";
						gpVtr_[width_ * (y - 1) + (x - 1)].name_ = turn_ ? "White Stone" : "Black Stone";
						if (displayLength_ < gpVtr_[width_ * (y - 1) + (x - 1)].display_.size())
						{
							displayLength_ = gpVtr_[width_ * (y - 1) + (x - 1)].display_.size();
						}
						valid = true;
						returnVal = i;
					}
				}
			}
			else // if (i == USER_QUIT)
			{
				valid = true;
				returnVal = i;
			}
		}
	}

	if (returnVal == SUCCESS)
	{
		print();
		cout << endl;
		cout << gpVtr_[width_ * (y - 1) + (x - 1)].name_ << ": ";
		for (unsigned int xx = 0; xx < width_; ++xx)
		{
			for (unsigned int yy = 0; yy < height_; ++yy)
			{
				if (gpVtr_[width_ * yy + xx].name_ == gpVtr_[width_ * (y - 1) + (x - 1)].name_)
				{
					cout << (xx + 1) << "," << (yy + 1) << "; ";
				}
			}
		}
		cout << endl;
		cout << endl;
	}
	
	return returnVal;
}
