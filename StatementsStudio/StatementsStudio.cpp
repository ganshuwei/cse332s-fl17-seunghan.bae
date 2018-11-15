// StatementsStudio.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void thrower()
{
	cout << "thrower function" << endl;

	char c = 'c';
	int i = 2;
	long l = 3L;
	string s = "string";
	char * cp = &c;
	int * ip = &i;
	long * lp = &l;

	throw lp;
}

int main(int argc, char * argv[])
{
	try	{
		thrower();
	}
	catch (char c) {
		cout << c << endl;
		return 1;
	}
	catch (int i) {
		cout << i << endl;
		return 2;
	}
	catch (long l) {
		cout << l << endl;
		return 3;
	}
	catch (string &s) {
		cout << s << endl;
		return 4;
	}
	catch (char * cp) {
		cout << * cp << endl;
		return 5;
	}
	catch (int * ip) {
		cout << * ip << endl;
		return 6;
	}
	catch (...) {
		cout << "unrecognized type was cought" << endl;
		return 7;
	}
	
	return 0;
}

