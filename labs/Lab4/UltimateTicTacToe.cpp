// UltimateTicTacToe.cpp
// Seunghan Bae (seunghan.bae@wustl.edu)
// (Lab 4) source file for the UltimateTicTacToe class
//

#include "stdafx.h"
#include "UltimateTicTacToe.h"
#include <fstream>

using namespace std;

// prints out the UltimateTicTacToe game
// os: ostream used for printing
// uttt: UltimateTicTacToe game to be printed
std::ostream & operator<<(std::ostream & os, const UltimateTicTacToe & uttt)
{
	for (int y = uttt.height_ - 1; y >= 0; --y)
	{
		os.width(1);
		os << y;
		for (unsigned int x = 0; x < uttt.width_; ++x)
		{
			os.width(1);
			os << " ";
			os.width(uttt.displayLength_);
			os << right << uttt.gpVtr_[uttt.width_ * y + x].display_;
			if ((x == 3 || x == 6) && (y != 0) && (y != 10))
			{
				os.width(1);
				os << " |";
			}
		}
		os << endl;
		if (y == 4 || y == 7)
		{
			os << "   -------+-------+-------" << endl;
		}
	}
	os.width(1);
	os << " ";
	for (unsigned int x = 0; x < uttt.width_; ++x)
	{
		os.width(1);
		os << " ";
		os.width(uttt.displayLength_);
		os << right << x;
		if (x == 3 || x == 6)
		{
			os.width(1);
			os << "  ";
		}
	}

	return os;
}

// default constructor for the UltimateTicTacToe class
UltimateTicTacToe::UltimateTicTacToe() : GameBase(UTTT_DIM, UTTT_DIM)
{
	for (int i = 0; i < 9; ++i)
	{
		uVtr_.push_back(" ");
	}

	ifstream ifs("UltimateTicTacToe.txt");
	if (ifs.is_open())
	{
		string s;
		ifs >> s;
		if (s == "UltimateTicTacToe")
		{
			bool turn;
			unsigned int turnCount;
			if ((ifs >> turn) && (ifs >> turnCount))
			{
				turn_ = turn;
				turnCount_ = turnCount;
			}
			vector<string> vtr;
			for (unsigned int i = 0; i < pieceCount_; ++i)
			{
				string temp;
				if (ifs >> temp)
				{
					vtr.push_back(temp);
				}
				if (vtr[i] != "NO")
				{
					gpVtr_[i].color_ = (vtr[i] == "O") ? RED : BLUE;
					gpVtr_[i].display_ = vtr[i];
					gpVtr_[i].name_ = "Player " + vtr[i];
					if (displayLength_ < gpVtr_[i].display_.length())
					{
						displayLength_ = gpVtr_[i].display_.length();
					}
				}
			}

			cout << "loading saved game..." << endl;
			cout << endl;
		}
		else // if (s == "NoData")
		{
			cout << "file has no data: starting a new game" << endl;
			cout << endl;
		}
	}
	else
	{
		cout << "cannot read file: starting a new game" << endl;
		cout << endl;
	}
	ifs.close();
}

// copy constructor for the UltimateTicTacToe class
UltimateTicTacToe::UltimateTicTacToe(const UltimateTicTacToe & u) : GameBase(u)
{
	for (unsigned int i = 0; i < u.uVtr_.size(); ++i)
	{
		uVtr_.push_back(u.uVtr_[i]);
	}
}

// move constructor for the UltimateTicTacToe class
UltimateTicTacToe::UltimateTicTacToe(UltimateTicTacToe && u) : GameBase(u)
{
	for (unsigned int i = 0; i < u.uVtr_.size(); ++i)
	{
		uVtr_.push_back(u.uVtr_[i]);
	}
	for (unsigned int i = 0; i < u.uVtr_.size(); ++i)
	{
		u.uVtr_.pop_back();
	}
}

// destructor for the UltimateTicTacToe class
UltimateTicTacToe::~UltimateTicTacToe()
{
	for (unsigned int i = 0; i < gpVtr_.size(); ++i)
	{
		gpVtr_.pop_back();
	}
	for (unsigned int i = 0; i < uVtr_.size(); ++i)
	{
		uVtr_.pop_back();
	}
}

// copy-assignment operator for the UltimateTicTacToe class
UltimateTicTacToe & UltimateTicTacToe::operator=(const UltimateTicTacToe & u)
{
	if (&u != this)
	{
		UltimateTicTacToe temp(u);
		swap(temp.width_, width_);
		swap(temp.height_, height_);
		swap(temp.pieceCount_, pieceCount_);
		swap(temp.turn_, turn_);
		swap(temp.turnCount_, turnCount_);
		swap(temp.displayLength_, displayLength_);

		for (unsigned int i = 0; i < gpVtr_.size(); ++i)
		{
			gpVtr_.pop_back();
		}
		for (unsigned int i = 0; i < temp.gpVtr_.size(); ++i)
		{
			gpVtr_.push_back(temp.gpVtr_[i]);
		}

		for (unsigned int i = 0; i < uVtr_.size(); ++i)
		{
			uVtr_.pop_back();
		}
		for (unsigned int i = 0; i < temp.uVtr_.size(); ++i)
		{
			uVtr_.push_back(temp.uVtr_[i]);
		}
	}

	return *this;
}

// move-assignment operator for the UltimateTicTacToe class
UltimateTicTacToe & UltimateTicTacToe::operator=(UltimateTicTacToe && u)
{
	if (&u != this)
	{
		width_ = u.width_;
		height_ = u.height_;
		pieceCount_ = u.pieceCount_;
		turn_ = u.turn_;
		turnCount_ = u.turnCount_;
		displayLength_ = u.displayLength_;
		u.width_ = 0;
		u.height_ = 0;
		u.pieceCount_ = 0;
		u.turnCount_ = 0;
		u.displayLength_ = 0;

		for (unsigned int i = 0; i < gpVtr_.size(); ++i)
		{
			gpVtr_.pop_back();
		}
		for (unsigned int i = 0; i < u.gpVtr_.size(); ++i)
		{
			gpVtr_.push_back(u.gpVtr_[i]);
		}
		for (unsigned int i = 0; i < u.gpVtr_.size(); ++i)
		{
			u.gpVtr_.pop_back();
		}

		for (unsigned int i = 0; i < uVtr_.size(); ++i)
		{
			uVtr_.pop_back();
		}
		for (unsigned int i = 0; i < u.uVtr_.size(); ++i)
		{
			uVtr_.push_back(u.uVtr_[i]);
		}
		for (unsigned int i = 0; i < u.uVtr_.size(); ++i)
		{
			u.uVtr_.pop_back();
		}
	}

	return *this;
}

// prints out the TicTacToe game
void UltimateTicTacToe::print()
{
	cout << *this << endl;
}

// returns true when either of the players won the entire game
bool UltimateTicTacToe::done()
{
	subDone();

	bool row1 = (uVtr_[0] != " ") && (uVtr_[0] == uVtr_[1]) && (uVtr_[1] == uVtr_[2]);
	bool row2 = (uVtr_[3] != " ") && (uVtr_[3] == uVtr_[4]) && (uVtr_[4] == uVtr_[5]);
	bool row3 = (uVtr_[6] != " ") && (uVtr_[6] == uVtr_[7]) && (uVtr_[7] == uVtr_[8]);
	bool col1 = (uVtr_[0] != " ") && (uVtr_[0] == uVtr_[3]) && (uVtr_[3] == uVtr_[6]);
	bool col2 = (uVtr_[1] != " ") && (uVtr_[1] == uVtr_[4]) && (uVtr_[4] == uVtr_[7]);
	bool col3 = (uVtr_[2] != " ") && (uVtr_[2] == uVtr_[5]) && (uVtr_[5] == uVtr_[8]);
	bool diag1 = (uVtr_[0] != " ") && (uVtr_[0] == uVtr_[4]) && (uVtr_[4] == uVtr_[8]);
	bool diag2 = (uVtr_[2] != " ") && (uVtr_[2] == uVtr_[4]) && (uVtr_[4] == uVtr_[6]);

	bool result = (row1 || row2 || row3 || col1 || col2 || col3 || diag1 || diag2);
	if (result)
	{
		string player = turn_ ? "O" : "X";
		cout << "Player " << player << " wins" << endl;

		cout << endl;
		print();

		ofstream ofs("UltimateTicTacToe.txt");
		if (ofs.is_open())
		{
			ofs << "NoData";
		}
		ofs.close();
	}

	return result;
}

// checks if either of the players won the sub-TicTacToe game
void UltimateTicTacToe::subDone()
{
	unsigned int subset[9][9] = { { 12, 13, 14, 23, 24, 25, 34, 35, 36 }, // sub-TicTacToe 1
								  { 15, 16, 17, 26, 27, 28, 37, 38, 39 }, // sub-TicTacToe 2
								  { 18, 19, 20, 29, 30, 31, 40, 41, 42 }, // sub-TicTacToe 3
								  { 45, 46, 47, 56, 57, 58, 67, 68, 69 }, // sub-TicTacToe 4
								  { 48, 49, 50, 59, 60, 61, 70, 71, 72 }, // sub-TicTacToe 5
								  { 51, 52, 53, 62, 63, 64, 73, 74, 75 }, // sub-TicTacToe 6
								  { 78, 79, 80, 89, 90, 91, 100, 101, 102 }, // sub-TicTacToe 7
								  { 81, 82, 83, 92, 93, 94, 103, 104, 105 }, // sub-TicTacToe 8
								  { 84, 85, 86, 95, 96, 97, 106, 107, 108 } }; // sub-TicTacToe 9

	for (int i = 0; i < 9; ++i)
	{
		if (uVtr_[i] == " ") // only check unfinished sub-TicTacToe games
		{
			bool row1 = (gpVtr_[subset[i][0]].display_ != " ") && (gpVtr_[subset[i][0]].display_ == gpVtr_[subset[i][1]].display_) && (gpVtr_[subset[i][1]].display_ == gpVtr_[subset[i][2]].display_);
			bool row2 = (gpVtr_[subset[i][3]].display_ != " ") && (gpVtr_[subset[i][3]].display_ == gpVtr_[subset[i][4]].display_) && (gpVtr_[subset[i][4]].display_ == gpVtr_[subset[i][5]].display_);
			bool row3 = (gpVtr_[subset[i][6]].display_ != " ") && (gpVtr_[subset[i][6]].display_ == gpVtr_[subset[i][7]].display_) && (gpVtr_[subset[i][7]].display_ == gpVtr_[subset[i][8]].display_);
			bool col1 = (gpVtr_[subset[i][0]].display_ != " ") && (gpVtr_[subset[i][0]].display_ == gpVtr_[subset[i][3]].display_) && (gpVtr_[subset[i][3]].display_ == gpVtr_[subset[i][6]].display_);
			bool col2 = (gpVtr_[subset[i][1]].display_ != " ") && (gpVtr_[subset[i][1]].display_ == gpVtr_[subset[i][4]].display_) && (gpVtr_[subset[i][4]].display_ == gpVtr_[subset[i][7]].display_);
			bool col3 = (gpVtr_[subset[i][2]].display_ != " ") && (gpVtr_[subset[i][2]].display_ == gpVtr_[subset[i][5]].display_) && (gpVtr_[subset[i][5]].display_ == gpVtr_[subset[i][8]].display_);
			bool diag1 = (gpVtr_[subset[i][0]].display_ != " ") && (gpVtr_[subset[i][0]].display_ == gpVtr_[subset[i][4]].display_) && (gpVtr_[subset[i][4]].display_ == gpVtr_[subset[i][8]].display_);
			bool diag2 = (gpVtr_[subset[i][2]].display_ != " ") && (gpVtr_[subset[i][2]].display_ == gpVtr_[subset[i][4]].display_) && (gpVtr_[subset[i][4]].display_ == gpVtr_[subset[i][6]].display_);

			bool result = (row1 || row2 || row3 || col1 || col2 || col3 || diag1 || diag2);
			if (result)
			{
				uVtr_[i] = turn_ ? "O" : "X";
				for (int j = 0; j < 9; ++j)
				{
					gpVtr_[subset[i][j]].color_ = turn_ ? RED : BLUE;
					gpVtr_[subset[i][j]].display_ = turn_ ? "O" : "X";
					gpVtr_[subset[i][j]].name_ = turn_ ? "Player O" : "Player X";
				}
			}
		}
	}
}

// returns true when the game ended draw
bool UltimateTicTacToe::draw()
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

	if (noMove && !done())
	{
		ofstream ofs("UltimateTicTacToe.txt");
		if (ofs.is_open())
		{
			ofs << "NoData";
		}
		ofs.close();

		return true;
	}
	else
	{
		return false;
	}
}

// receives input for each player's turn and prints out the board
int UltimateTicTacToe::turn()
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
				save();
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

// saves the game into a .txt file
void UltimateTicTacToe::save()
{
	char ans = ' ';
	char temp;
	cout << "save current game? (y/n): ";
	cin >> temp;
	cout << endl;

	ans = temp;
	ofstream ofs("UltimateTicTacToe.txt");
	if (ofs.is_open())
	{
		if (ans == 'y')
		{
			ofs << "UltimateTicTacToe" << "\r\n";
			ofs << (!turn_) << " " << turnCount_ << "\r\n";
			for (unsigned int i = 0; i < gpVtr_.size(); ++i)
			{
				ofs << (gpVtr_[i].display_ == " " ? "NO" : gpVtr_[i].display_) << " ";
			}
			ofs << "\r\n" << endl;
		}
		else // if (ans == 'n')
		{
			ofs << "NoData";
		}
	}
	else
	{
		cout << "cannot read file: cannot save game" << endl;
	}
	ofs.close();
}
