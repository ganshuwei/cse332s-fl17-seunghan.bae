// StringsAndArrayStudio.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

int main(int argc, char * argv[])
{
	/*unsigned int arr[2][3][5];
	for (int x = 0; x < 2; ++x)
	{
		for (int y = 0; y < 3; ++y)
		{
			for (int z = 0; z < 5; ++z)
			{
				arr[x][y][z] = x * y * z;
				cout << "[" << x << "][" << y << "][" << z << "] " << arr[x][y][z] << " " << &arr[x][y][z] << endl;
			}
		}
	}*/

	/*vector<string> v;
	for (int i = 0; i < argc; ++i)
	{
		v.push_back(argv[i]);
	}
	for (int j = 0; j < v.size(); ++j)
	{
		cout << v[j] << endl;
	}*/

	/*string s;
	for (int i = 0; i < argc; ++i)
	{
		s += argv[i];
		s += " ";
	}
	istringstream iss(s);
	while (iss)
	{
		string str;
		iss >> str;
		cout << str << endl;
	}*/

	/*if (argc == 3)
	{
		for (int i = 0; i < argc; ++i)
		{
			cout << argv[i] << endl;
		}
	}
	else
	{
		cout << "usage: " << argv[0] << " arg1 arg2" << endl;
		return 1;
	}*/

	if (argc == 3)
	{
		ifstream ifs(argv[1]);

		if (ifs.is_open())
		{
			ofstream ofs(argv[2]);

			if (ofs.is_open())
			{
				while (ifs)
				{
					string str;
					ifs >> str;
					ofs << str;
				}
			}
			else
			{
				cout << "error: could not open '" << argv[2] << "' for writing" << endl;
				return 3;
			}

			ifs.close();
			ofs.close();
		}
		else
		{
			cout << "error: could not open '" << argv[1] << "' for reading" << endl;
			return 2;
		}
	}
	else
	{
		cout << "usage: " << argv[0] << " input output" << endl;
		return 1;
	}

	return 0;
}

