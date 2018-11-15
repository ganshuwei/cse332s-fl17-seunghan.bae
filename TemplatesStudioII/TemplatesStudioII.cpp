// TemplatesStudioII.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TemplatesStudioII.h"
#include <list>

using namespace std;

int main(int argc, char * argv[])
{
	int arr[] = { 1, 2, 3, 4 };
	list<int> lst;
	lst.push_back(5);
	lst.push_back(6);
	lst.push_back(7);

	cout << "array: " << counter(arr, arr + 4) << endl;
	cout << "list: " << counter(lst.begin(), lst.end()) << endl;

	char charr[] = { 'a', 'r', 'r', 'a', 'y' };
	cout << "char array: " << counter(charr, charr + 5) << endl;

	char * str = "string";
	cout << "c-style string: " << counter(str, str + 6) << endl;

	double darr[] = { 0.2, 0.3 };
	cout << "double: " << counter(darr, darr + 2) << endl;

	return 0;
}

