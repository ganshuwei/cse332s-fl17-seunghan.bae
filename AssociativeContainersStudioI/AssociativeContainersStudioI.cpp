// AssociativeContainersStudioI.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <set>
#include <iterator>
#include <map>

using namespace std;

bool greater(const string & s1, const string & s2)
{
	return (s1 > s2);
}

int main(int argc, char * argv[])
{
	multiset<string> ss;
	copy(argv, argv + argc, inserter(ss, ss.end()));
	ostream_iterator<string> ois(cout, " ");
	copy(ss.begin(), ss.end(), ois);

	cout << endl;
	
	multiset<char *> sc;
	copy(argv, argv + argc, inserter(sc, sc.end()));
	ostream_iterator<char *> oic(cout, " ");
	copy(sc.begin(), sc.end(), oic);

	cout << endl;

	multiset<string, decltype(greater) *> ss2(greater);
	copy(argv, argv + argc, inserter(ss2, ss2.end()));
	copy(ss2.begin(), ss2.end(), ois);

	cout << endl;

	// map<string, unsigned int> msi;

	return 0;
}

