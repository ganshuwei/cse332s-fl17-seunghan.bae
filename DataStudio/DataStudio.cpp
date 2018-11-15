// DataStudio.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main(int argc, char * argv[])
{
	// cout << argv[0] << endl;

	// const char & ptr; - ERROR
	// auto ptr = *argv;
	// decltype(*argv) ptr;
	for (int i = 0; i < argc; ++i)
	{
		for (const char * ptr = *argv; *ptr != '\0'; ++ptr)
		{
			cout << *ptr << endl;
		}

		++argv;
	}

	return 0;
}

