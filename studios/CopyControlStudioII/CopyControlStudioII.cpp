// CopyControlStudioII.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Detector.h"
#include <iostream>

using namespace std;

int main(int argc, char * argv[])
{
	/* int x = 2;
	int y = 5;
	int & lvrx = x;
	int & lvry = y;
	// int && rvrx = x + 7;
	int && rvrx = move(x);
	// int && rvry = y * 3;
	int && rvry = move(y);

	int x2 = x;
	int y2 = y;
	x2 = y;
	y2 = x;

	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	cout << "lvrx = " << lvrx << endl;
	cout << "lvry = " << lvry << endl;
	cout << "rvrx = " << rvrx << endl;
	cout << "rvry = " << rvry << endl;
	cout << "x2 = " << x2 << endl;
	cout << "y2 = " << y2 << endl; */

	wrapper w1;
	wrapper w4(w1);
	wrapper w5(move(w1));

	return 0;
}

