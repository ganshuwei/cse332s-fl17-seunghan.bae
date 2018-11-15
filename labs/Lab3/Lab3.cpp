// Lab3.cpp
// Seunghan Bae (seunghan.bae@wustl.edu)
// (Lab 3) main application source file
//

#include "stdafx.h"
#include "GameClasses.h"
#include <memory>

using namespace std;

int main(int argc, char * argv[])
{
	GameBase * gb = GameBase::start(argc, argv);
	if (gb == 0)
	{
		return usageMsg(argv[PROGRAM], "<TicTacToe/Gomoku>", "<board_dimension>", "<#_connect>");
	}
	else
	{
		shared_ptr<GameBase> spg(gb);
		int result = spg->play();
		return result;
	}
}

int usageMsg(char * c1, char * c2, char * c3, char * c4)
{
	cout << "usage: " << c1 << " " << c2 << " " << c3 << " " << c4 << endl;
	return WRONG_ARGUMENT;
}
