// CopyControlStudioI.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Detector.h"
#include <iostream>

using namespace std;

int main()
{
	// wrapper w;
	// wrapper r(w);
	wrapper * w = new wrapper;
	wrapper * r = new wrapper(*w);

	delete w;
	delete r;

	return 0;
}

