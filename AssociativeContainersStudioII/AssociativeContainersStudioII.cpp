// AssociativeContainersStudioII.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <set>
#include <iterator>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;

int main(int argc, char * argv[])
{
	set<string> ss;
	auto in0 = ss.insert("one");
	auto in1 = ss.insert("two");
	auto in2 = ss.insert("three");
	auto in3 = ss.insert("one");
	auto in4 = ss.insert("one");

	cout << in1.second << " ";
	cout << in2.second << " ";
	cout << in3.second << " ";
	cout << in4.second << endl;

	multiset<string> ms;
	auto in5 = ms.insert("one");
	auto in6 = ms.insert("two");
	auto in7 = ms.insert("three");
	auto in8 = ms.insert("one");
	auto in9 = ms.insert("one");

	auto eqItr = ms.equal_range("one");
	ostream_iterator<string> ois(cout, " ");
	copy(eqItr.first, eqItr.second, ois);
	cout << endl;

	// ms.erase(eqItr.first);
	// ms.erase(eqItr.first, eqItr.second);
	ms.erase(++eqItr.first, eqItr.second);
	auto eqItr2 = ms.equal_range("one");
	copy(eqItr2.first, eqItr2.second, ois);
	cout << endl;

	unordered_multimap<string, int> msi;
	auto in10 = msi.insert(make_pair("one", 5));
	auto in11 = msi.insert(make_pair("one", 4));
	auto in12 = msi.insert(pair<string, int>("two", 2));
	auto in13 = msi.insert(pair<string, int>("one", 1));
	auto in14 = msi.insert(map<string, int>::value_type("three", 3));

	auto eqItr3 = msi.equal_range("one");
	for (auto itr = eqItr3.first; itr != eqItr3.second; ++itr)
	{
		cout << "(" << itr->first << ", " << itr->second << ") ";
	}
	cout << endl;

	// msi.erase(eqItr3.first);
	// msi.erase(eqItr3.first, eqItr3.second);s
	msi.erase(++eqItr3.first, eqItr3.second);
	auto eqItr4 = msi.equal_range("one");
	for (auto itr = eqItr4.first; itr != eqItr4.second; ++itr)
	{
		cout << "(" << itr->first << ", " << itr->second << ") ";
	}

    return 0;
}

