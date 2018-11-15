// AlgorithmsStudioII.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <deque>
#include <list>
#include <forward_list>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>

using namespace std;

bool larger(int x, int y)
{
	return x > y;
}

struct bigger
{
	bool operator() (int x, int y)
	{
		return x > y;
	}
};

int main(int argc, char * argv[])
{
	ostream_iterator<int> oi(cout, " ");

	/* deque<int> d;
	list<int> l;
	forward_list<int> f;
	vector<int> v;
	for (int i = 1; i <= 5; ++i)
	{
		d.push_back(i);
		l.push_back(i);
		f.push_front(6 - i);
		v.push_back(i);
	}

	cout << *(d.begin() + 2) << endl;
	// error: cout << *(l.begin() + 2) << endl;
	list<int>::iterator lp = l.begin();
	++lp;
	++lp;
	cout << *lp << endl;
	// error: cout << *(f.begin() + 2) << endl;
	forward_list<int>::iterator fp = f.begin();
	++fp;
	++fp;
	cout << *fp << endl;
	cout << *(v.begin() + 2) << endl;

	for (size_t i = 0; i < v.size(); ++i)
	{
		for (int j = v.size() - i; j >= 0; --j)
		{
			copy(v.begin() + i, v.end() - j, oi);
			cout << endl;
		}
	} */

	int arr[] = { -2, 19, 80, -47, 80, 80, -2 };
	int * last = arr + 7;
	copy(arr, last, oi);
	cout << endl;
	// sort(arr, last, greater<int>());
	// sort(arr, last, larger);
	// sort(arr, last, bigger());
	sort(arr, last, [](int x, int y) -> bool { return x > y; });
	copy(arr, last, oi);
	cout << endl;

	auto binder = bind(larger, placeholders::_1, 0);
	for (int i = 0; i < 7; ++i)
	{
		if (binder(arr[i]))
		{
			cout << arr[i] << " ";
		}
	}
	cout << endl;

	return 0;
}

