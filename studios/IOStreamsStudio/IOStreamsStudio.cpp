// IOStreamsStudio.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Classes.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char * argv[])
{
	/*TwoInts t;
	cout << "Enter 2 ints (hit Ctrl+C to quit): ";
	cin >> t;
	cout << endl << "You entered " << t << endl;*/

	ifstream ifs("int.txt");
	if (ifs.is_open())
	{
		ofstream ofs("twoints.txt");
		TwoInts t;
		while (ifs >> t)
		{
			//cout << t << endl;
			ofs << t << endl;
		}
		ofs.close();
	}
	ifs.close();

	return 0;
}

