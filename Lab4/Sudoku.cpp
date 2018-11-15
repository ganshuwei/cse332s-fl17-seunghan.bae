// Sudoku.cpp
// Seunghan Bae (seunghan.bae@wustl.edu)
// (Lab 4) source file for the Sudoku class
//

#include "stdafx.h"
#include "Sudoku.h"
#include <fstream>
#include <sstream>

using namespace std;

// prints out the Sudoku game
// os: ostream used for printing
// sdk: TicTacToe game to be printed
std::ostream & operator<<(std::ostream & os, const Sudoku & sdk)
{
	for (int y = sdk.height_ - 1; y >= 0; --y)
	{
		os.width(1);
		os << y << "||";
		for (unsigned int x = 0; x < sdk.width_; ++x)
		{
			os.width(sdk.displayLength_);
			os << right << sdk.gpVtr_[sdk.width_ * y + x].display_;
			os.width(1);
			if (x % 3 == 2)
			{
				os << "||";
			}
			else
			{
				os << "|";
			}
		}
		os << endl;

		if (y % 3 == 0)
		{
			os << "=||";
			for (unsigned int x = 0; x < sdk.width_; ++x)
			{
				os << "=";
				if (x % 3 == 2)
				{
					os << "||";
				}
				else
				{
					os << "|";
				}
			}
			os << endl;
		}
		else
		{
			os << "-||";
			for (unsigned int x = 0; x < sdk.width_; ++x)
			{
				os << "-";
				if (x % 3 == 2)
				{
					os << "||";
				}
				else
				{
					os << "|";
				}
			}
			os << endl;
		}
	}

	os.width(1);
	os << "#||";
	for (unsigned int x = 0; x < sdk.width_; ++x)
	{
		os.width(sdk.displayLength_);
		os << right << x;
		if (x % 3 == 2)
		{
			os << "||";
		}
		else
		{
			os << "|";
		}
	}

	return os;
}

// default constructor for the Sudoku class
Sudoku::Sudoku() : GameBase(SDK_DIM, SDK_DIM)
{
	ifstream ifs("Sudoku.txt");
	if (ifs.is_open())
	{
		string s;
		ifs >> s;
		if (s == "Sudoku")
		{
			unsigned int turnCount;
			if (ifs >> turnCount)
			{
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
				if (vtr[i] != "0")
				{
					gpVtr_[i].color_ = BLACK;
					gpVtr_[i].display_ = vtr[i];
					if (displayLength_ < gpVtr_[i].display_.size())
					{
						displayLength_ = gpVtr_[i].display_.size();
					}
				}
			}
			vector<string> vtr2;
			for (unsigned int j = 0; j < pieceCount_; ++j)
			{
				string temp2;
				if (ifs >> temp2)
				{
					vtr2.push_back(temp2);
				}
				if (vtr2[j] != "0")
				{
					gpVtr_[j].name_ = vtr2[j];
				}
			}

			cout << "loading saved game..." << endl;
			cout << endl;
		}
		else // if (s == "NoData")
		{
			cout << "file has no data: loading sudoku0.txt" << endl;
			loadSudoku0();
			cout << endl;
		}
		ifs.close();
	}
	else
	{
		cout << "cannot read file: loading sudoku0.txt" << endl;
		loadSudoku0();
		cout << endl;
	}
}

// copy constructor for the Sudoku class
Sudoku::Sudoku(const Sudoku & s) : GameBase(s)
{
}

// move constructor for the Sudoku class
Sudoku::Sudoku(Sudoku && s) : GameBase(s)
{
}

// destructor for the Sudoku class
Sudoku::~Sudoku()
{
	for (unsigned int i = 0; i < gpVtr_.size(); ++i)
	{
		gpVtr_.pop_back();
	}
}

// copy-assignment operator for the Sudoku class
Sudoku & Sudoku::operator=(const Sudoku & s)
{
	if (&s != this)
	{
		Sudoku temp(s);
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

// move-assignment operator for the Sudoku class
Sudoku & Sudoku::operator=(Sudoku && s)
{
	if (&s != this)
	{
		width_ = s.width_;
		height_ = s.height_;
		pieceCount_ = s.pieceCount_;
		turn_ = s.turn_;
		turnCount_ = s.turnCount_;
		displayLength_ = s.displayLength_;
		s.width_ = 0;
		s.height_ = 0;
		s.pieceCount_ = 0;
		s.turnCount_ = 0;
		s.displayLength_ = 0;

		for (unsigned int i = 0; i < gpVtr_.size(); ++i)
		{
			gpVtr_.pop_back();
		}
		for (unsigned int i = 0; i < s.gpVtr_.size(); ++i)
		{
			gpVtr_.push_back(s.gpVtr_[i]);
		}
		for (unsigned int i = 0; i < s.gpVtr_.size(); ++i)
		{
			s.gpVtr_.pop_back();
		}
	}

	return *this;
}

// loads sudoku0.txt to the game
void Sudoku::loadSudoku0()
{
	ifstream ifs0("sudoku0.txt");
	if (ifs0.is_open())
	{
		vector<string> vtr;
		for (unsigned int i = 0; i < pieceCount_; ++i)
		{
			string temp;
			if (ifs0 >> temp)
			{
				vtr.push_back(temp);
			}
			if (vtr[i] != "0")
			{
				gpVtr_[i].color_ = BLACK;
				gpVtr_[i].display_ = vtr[i];
				gpVtr_[i].name_ = "D"; // Default
				if (displayLength_ < gpVtr_[i].display_.size())
				{
					displayLength_ = gpVtr_[i].display_.size();
				}
			}
		}
		ifs0.close();
	}
}

// prints out the Sudoku game
void Sudoku::print()
{
	cout << *this << endl;
}

// returns true when all cells are filled correctly
bool Sudoku::done()
{
	int sum = 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9;
	unsigned int nineCells[27][9] = { { 0, 1, 2, 9, 10, 11, 18, 19, 20 }, // sub-square 1
									  { 3, 4, 5, 12, 13, 14, 21, 22, 23 }, // sub-square 2
									  { 6, 7, 8, 15, 16, 17, 24, 25, 26 }, // sub-square 3
									  { 27, 28, 29, 36, 37, 38, 45, 46, 47 }, // sub-square 4
									  { 30, 31, 32, 39, 40, 41, 48, 49, 50 }, // sub-square 5
									  { 33, 34, 35, 42, 43, 44, 51, 52, 53 }, // sub-square 6
									  { 54, 55, 56, 63, 64, 65, 72, 73, 74 }, // sub-square 7
									  { 57, 58, 59, 66, 67, 68, 75, 76, 77 }, // sub-square 8
									  { 60, 61, 62, 69, 70, 71, 78, 79, 80 }, // sub-square 9
									  { 0, 1, 2, 3, 4, 5, 6, 7, 8 }, // row 1
									  { 9, 10, 11, 12, 13, 14, 15, 16, 17 }, // row 2
									  { 18, 19, 20, 21, 22, 23, 24, 25, 26 }, // row 3
									  { 27, 28, 29, 30, 31, 32, 33, 34, 35 }, // row 4
									  { 36, 37, 38, 39, 40, 41, 42, 43, 44 }, // row 5
									  { 45, 46, 47, 48, 49, 50, 51, 52, 53 }, // row 6
									  { 54, 55, 56, 57, 58, 59, 60, 61, 62 }, // row 7
									  { 63, 64, 65, 66, 67, 68, 69, 70, 71 }, // row 8
									  { 72, 73, 74, 75, 76, 77, 78, 79, 80 }, // row 9
									  { 0, 9, 18, 27, 36, 45, 54, 63, 72 }, // column 1
									  { 1, 10, 19, 28, 37, 46, 55, 64, 73 }, // column 2
									  { 2, 11, 20, 29, 38, 47, 56, 65, 74 }, // column 3
									  { 3, 12, 21, 30, 39, 48, 57, 66, 75 }, // column 4
									  { 4, 13, 22, 31, 40, 49, 58, 67, 76 }, // column 5
									  { 5, 14, 23, 32, 41, 50, 59, 68, 77 }, // column 6
									  { 6, 15, 24, 33, 42, 51, 60, 69, 78 }, // column 7
									  { 7, 16, 25, 34, 43, 52, 61, 70, 79 }, // column 8
									  { 8, 17, 26, 35, 44, 53, 62, 71, 80 } }; // column 9

	int fillCount = 0;
	int sumCount = 0;
	for (unsigned int i = 0; i < gpVtr_.size(); ++i)
	{
		if (gpVtr_[i].display_ != " ")
		{
			++fillCount;
		}
	}
	for (int j = 0; j < 27; ++j)
	{
		int sumTemp = 0;
		for (int k = 0; k < 9; ++k)
		{
			if (gpVtr_[nineCells[j][k]].display_ != " ")
			{
				sumTemp += stoi(gpVtr_[nineCells[j][k]].display_);
			}
		}
		if (sumTemp == sum)
		{
			++sumCount;
		}
	}

	if ((fillCount == 81) && (sumCount == 27))
	{
		cout << "Done!" << endl;

		ofstream ofs("Sudoku.txt");
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

// always returns false (no "draw" in Sudoku)
bool Sudoku::draw()
{
	return false;
}

// prompts player to type either 'quit' or 'x,y:#'
// n1: x-coordinate of the game_piece
// n2: y-coordinate of the game_piece
// n3: number that the game_piece displays
void Sudoku::prompt(unsigned int & n1, unsigned int & n2, unsigned int & n3)
{
	bool valid = false;
	int returnVal;

	while (!valid) // repeats until valid string is received
	{
		cout << "type 'quit' or 'x,y:#' (# = 1 ~ 9): ";
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
				if ((s[i] == ',') || (s[i] == ':'))
				{
					s[i] = ' ';
				}
			}

			istringstream iss(s);
			if ((iss >> n1) && (iss >> n2) && (iss >> n3))
			{
				valid = true;
				returnVal = SUCCESS;
			}
		}
	}

	throw returnVal;
}

// receives input for the player's move and prints out the board
int Sudoku::turn()
{
	unsigned int x, y, n;
	bool valid = false;
	int returnVal = -1;

	while (!valid) // repeats until valid string is received
	{
		try
		{
			prompt(x, y, n);
		}
		catch (int i)
		{
			if (i == SUCCESS)
			{
				if (x >= 0 && x < width_ && y >= 0 && y < height_ && n >= 1 && n <= 9) // if x,y,n is within valid range
				{
					if (gpVtr_[width_ * y + x].display_ == " ") // if the coordinate is empty
					{
						gpVtr_[width_ * y + x].color_ = BLACK;
						gpVtr_[width_ * y + x].display_ = to_string(n);
						gpVtr_[width_ * y + x].name_ = "P"; // Player
						if (displayLength_ < gpVtr_[width_ * y + x].display_.size())
						{
							displayLength_ = gpVtr_[width_ * y + x].display_.size();
						}
						valid = true;
						returnVal = i;
					}
					else if ((gpVtr_[width_ * y + x].display_ != to_string(n)) && (gpVtr_[width_ * y + x].name_ == "P")) // if replacing an existing cell
					{
						gpVtr_[width_ * y + x].display_ = to_string(n);
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
	}

	return returnVal;
}

// saves the game into a .txt file
void Sudoku::save()
{
	char ans = ' ';
	char temp;
	cout << "save current game? (y/n): ";
	cin >> temp;
	cout << endl;

	ans = temp;
	ofstream ofs("Sudoku.txt");
	if (ofs.is_open())
	{
		if (ans == 'y')
		{
			ofs << "Sudoku" << "\r\n";
			ofs << turnCount_ << "\r\n";
			for (unsigned int i = 0; i < gpVtr_.size(); ++i)
			{
				ofs << (gpVtr_[i].display_ == " " ? "0" : gpVtr_[i].display_) << " ";
			}
			ofs << "\r\n";
			for (unsigned int j = 0; j < gpVtr_.size(); ++j)
			{
				ofs << (gpVtr_[j].name_ == "" ? "0" : gpVtr_[j].name_) << " ";
			}
			ofs << "\r\n" << endl;
		}
		else // if (ans == 'n')
		{
			ofs << "NoData";
		}
		ofs.close();
	}
	else
	{
		cout << "cannot read file: cannot save game" << endl;
	}
}

