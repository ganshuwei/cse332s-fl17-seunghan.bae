// Lab4.cpp
// Seunghan Bae (seunghan.bae@wustl.edu)
// (Lab 4) main application source file
//

#include "stdafx.h"
#include "TicTacToe.h"
#include "Gomoku.h"
#include "Sudoku.h"
#include "UltimateTicTacToe.h"

using namespace std;

int main(int argc, char * argv[])
{
	try
	{
		GameBase::start(argc, argv);
	}
	catch (errors e)
	{
		if (e == PTR_NOT_NULL)
		{
			cout << "exception: pointer_not_null" << endl;
			return PTR_NOT_NULL;
		}
		else
		{
			return usageMsg(argv[PROGRAM], "<game_name>", e);
		}
	}

	shared_ptr<GameBase> gamePtr;
	try
	{
		gamePtr = GameBase::instance();
	}
	catch (errors)
	{
		cout << "exception: null_pointer" << endl;
		return NULL_PTR_EXCEPTION;
	}

	try
	{
		return gamePtr->play();
	}
	catch (bad_alloc)
	{
		return BAD_ALLOC;
	}
}

int usageMsg(char * c1, char * c2, int enumVal)
{
	cout << "usage: " << c1 << " " << c2 << endl;
	return enumVal;
}
