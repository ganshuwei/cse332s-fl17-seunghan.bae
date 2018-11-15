// TicTacToe.cpp
// Seunghan Bae (seunghan.bae@wustl.edu)
// (Lab 4) source file for the TicTacToe class
//

#include "stdafx.h"
#include "TicTacToe.h"
#include <fstream>

using namespace std;

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
	ifstream ifs("TicTacToe.txt");
	if (ifs.is_open())
	{
		string s;
		ifs >> s;
		if (s == "TicTacToe")
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

// copy constructor for the TicTacToe class
TicTacToe::TicTacToe(const TicTacToe & t) : GameBase(t)
{
}

// move constructor for the TicTacToe class
TicTacToe::TicTacToe(TicTacToe && t) : GameBase(t)
{
}

// destructor for the TicTacToe class
TicTacToe::~TicTacToe()
{
	for (unsigned int i = 0; i < gpVtr_.size(); ++i)
	{
		gpVtr_.pop_back();
	}
}

// copy-assignment operator for the TicTacToe class
TicTacToe & TicTacToe::operator=(const TicTacToe & t)
{
	if (&t != this)
	{
		TicTacToe temp(t);
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
	}

	return *this;
}

// move-assignment operator for the TicTacToe class
TicTacToe & TicTacToe::operator=(TicTacToe && t)
{
	if (&t != this)
	{
		width_ = t.width_;
		height_ = t.height_;
		pieceCount_ = t.pieceCount_;
		turn_ = t.turn_;
		turnCount_ = t.turnCount_;
		displayLength_ = t.displayLength_;
		t.width_ = 0;
		t.height_ = 0;
		t.pieceCount_ = 0;
		t.turnCount_ = 0;
		t.displayLength_ = 0;

		for (unsigned int i = 0; i < gpVtr_.size(); ++i)
		{
			gpVtr_.pop_back();
		}
		for (unsigned int i = 0; i < t.gpVtr_.size(); ++i)
		{
			gpVtr_.push_back(t.gpVtr_[i]);
		}
		for (unsigned int i = 0; i < t.gpVtr_.size(); ++i)
		{
			t.gpVtr_.pop_back();
		}
	}

	return *this;
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

		ofstream ofs("TicTacToe.txt");
		if (ofs.is_open())
		{
			ofs << "NoData";
		}
		ofs.close();
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

	if (noMove && !done())
	{
		ofstream ofs("TicTacToe.txt");
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
void TicTacToe::save()
{
	char ans = ' ';
	char temp;
	cout << "save current game? (y/n): ";
	cin >> temp;
	cout << endl;

	ans = temp;
	ofstream ofs("TicTacToe.txt");
	if (ofs.is_open())
	{
		if (ans == 'y')
		{
			ofs << "TicTacToe" << "\r\n";
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
