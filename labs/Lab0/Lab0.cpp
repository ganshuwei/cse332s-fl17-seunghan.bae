// Lab0.cpp
// Seunghan Bae (seunghan.bae@wustl.edu)
// (Lab 0) main application source file
//

#include "stdafx.h"
#include "Lab0.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char * argv[])
{
	// Check if expected number of command line arguments are given
	if (argc == EXPECTED_ARG_NUM)
	{
		// Create a vector of C++ string,
		// Parse the input file,
		// Push the strings back to the vector
		vector<string> strVtr;
		int returnValue = parseInput(strVtr, argv[INPUT_FILE]);

		// If parsing was unsuccessful, return the corresponding failure value and end the program
		if (returnValue != SUCCESS)
		{
			return returnValue;
		}

		// Create a vector of int,
		// Check if each string only contains numeric characters,
		// If so: push the int back to the vector,
		// If not: print out the string
		vector<int> intVtr;
		for (size_t s = 0; s < strVtr.size(); ++s)
		{
			string str = strVtr[s];
			size_t count = 0;

			for (size_t c = 0; c < str.length(); ++c)
			{
				if (isdigit(str[c]))
				{
					++count;
				}
			}

			if (count == str.length())
			{
				int intString;
				istringstream iss(str);
				iss >> intString;
				intVtr.push_back(intString);
			}
			else
			{
				cout << str << endl;
			}
		}

		// print out the ints
		for (size_t i = 0; i < intVtr.size(); ++i)
		{
			cout << intVtr[i] << endl;
		}
		
		return SUCCESS;
	}
	else // if there are too many or too few command line arguments
	{
		return usageMsg(argv[PROGRAM]);
	}
}

// parses the input file
// v: vector of C++ style string (reference)
// c: C-style string
int parseInput(vector<string> & v, char * c)
{
	ifstream ifs(c);
	if (ifs.is_open())
	{
		while (ifs)
		{
			string s;
			ifs >> s;
			if (s != "")
			{
				v.push_back(s);
			}
		}
		ifs.close();

		if (v.size() == 0) // if the input file is empty
		{
			cout << "error: file '" << c << "' is empty" << endl;
			return FILE_IS_EMPTY;
		}
		else
		{
			return SUCCESS;
		}
	}
	else // if the input file cannot be opened
	{
		cout << "error: cannot open file '" << c << "'" << endl;
		return CANNOT_OPEN_FILE;
	}
}

// prints out the "usage message"
// c: C-style string
int usageMsg(char * c)
{
	cout << "usage: " << c << " <input_file_name>" << endl;
	return WRONG_ARG_NUM;
}
