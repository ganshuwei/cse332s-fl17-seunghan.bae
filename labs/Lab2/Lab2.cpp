// Lab2.cpp
// Seunghan Bae (seunghan.bae@wustl.edu)
// (Lab 2) main application source file

#include "stdafx.h"
#include "TicTacToe.h"

using namespace std;

int main(int argc, char * argv[])
{
	if (argc == EXPECTED_ARG_NUM && strcmp(argv[1], "TicTacToe") == 0)
	{
		TicTacToeGame ttt;
		return ttt.play();
	}
	else if (argc == EXTRA_ARG_NUM && strcmp(argv[1], "TicTacToe") == 0 && strcmp(argv[2], "auto_player") == 0) // extra credit
	{
		TicTacToeGame ttt(true);
		return ttt.play();
	}
	else
	{
		return usageMsg(argv[PROGRAM], "TicTacToe", "auto_player(optional)");
	}
}

// prints out the usage message
// c1: name of the program (argv[0])
// c2: first command line argument, which is the input file name (argv[1])
int usageMsg(char * c1, char * c2, char * c3)
{
	cout << "usage: " << c1 << " " << c2 << " " << c3 << endl;
	return WRONG_ARGUMENT;
}
