// Gomoku.cpp
// Seunghan Bae (seunghan.bae@wustl.edu)
// (Lab 4) source file for the Gomoku class
//

#include "stdafx.h"
#include "Gomoku.h"
#include <fstream>

using namespace std;

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
	ifstream ifs("Gomoku.txt");
	if (ifs.is_open())
	{
		string s;
		ifs >> s;
		if (s == "Gomoku")
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
					gpVtr_[i].color_ = (vtr[i] == "W") ? WHITE : BLACK;
					gpVtr_[i].display_ = vtr[i];
					gpVtr_[i].name_ = (vtr[i] == "W") ? "White Stone" : "Black Stone";
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

// copy constructor for the Gomoku class
Gomoku::Gomoku(const Gomoku & g) : GameBase(g), connect_(g.connect_)
{
}

// move constructor for the Gomoku class
Gomoku::Gomoku(Gomoku && g) : GameBase(g), connect_(g.connect_)
{
	g.connect_ = 0;
}

// destructor for the Gomoku class
Gomoku::~Gomoku()
{
	for (unsigned int i = 0; i < gpVtr_.size(); ++i)
	{
		gpVtr_.pop_back();
	}
}

// copy-assignment operator for the Gomoku class
Gomoku & Gomoku::operator=(const Gomoku & g)
{
	if (&g != this)
	{
		Gomoku temp(g);
		swap(temp.width_, width_);
		swap(temp.height_, height_);
		swap(temp.pieceCount_, pieceCount_);
		swap(temp.turn_, turn_);
		swap(temp.turnCount_, turnCount_);
		swap(temp.displayLength_, displayLength_);
		swap(temp.connect_, connect_);

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

// move-assignment operator for the Gomoku class
Gomoku & Gomoku::operator=(Gomoku && g)
{
	if (&g != this)
	{
		width_ = g.width_;
		height_ = g.height_;
		pieceCount_ = g.pieceCount_;
		turn_ = g.turn_;
		turnCount_ = g.turnCount_;
		displayLength_ = g.displayLength_;
		connect_ = g.connect_;
		g.width_ = 0;
		g.height_ = 0;
		g.pieceCount_ = 0;
		g.turnCount_ = 0;
		g.displayLength_ = 0;
		g.connect_ = 0;

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

					ofstream ofs("Gomoku.txt");
					if (ofs.is_open())
					{
						ofs << "NoData";
					}
					ofs.close();

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

	ofstream ofs("Gomoku.txt");
	if (ofs.is_open())
	{
		ofs << "NoData";
	}
	ofs.close();

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

// saves the game into a .txt file
void Gomoku::save()
{
	char ans = ' ';
	char temp;
	cout << "save current game? (y/n): ";
	cin >> temp;
	cout << endl;

	ans = temp;
	ofstream ofs("Gomoku.txt");
	if (ofs.is_open())
	{
		if (ans == 'y')
		{
			ofs << "Gomoku" << "\r\n";
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
