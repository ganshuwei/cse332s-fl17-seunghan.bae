// DevEnvStudio.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	//cout << "hello, world!" << endl;

	string names;
	names = names + "seunghan ";
	names += "skylar";
	cout << names << endl;

	size_t len = names.length();
	cout << len << endl;
	
	return 0;
}

