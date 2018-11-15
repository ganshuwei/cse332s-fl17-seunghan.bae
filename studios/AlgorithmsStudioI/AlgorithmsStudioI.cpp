// AlgorithmsStudioI.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main(int argc, char * argv[])
{
	int arr[] = { -2, 19, 80, -47, 80, 80, -2 };
	int * last = arr + 7;

	vector<int> iv;
	back_insert_iterator<vector<int>> bii (iv);
	copy(arr, last, bii);

	sort(arr, last);
	sort(iv.begin(), iv.end());

	ostream_iterator<int> oi (cout, " ");
	// copy(arr, last, oi);
	// cout << endl;
	copy(iv.begin(), iv.end(), oi);
	cout << endl;

	vector<int>::iterator af = adjacent_find(iv.begin(), iv.end());
	while (af != iv.end())
	{
		int nCount = 0;
		//for (int n : iv)
		for (vector<int>::iterator vi = af; vi != iv.end(); ++vi)
		{
			if (*vi == *af)
			{
				++nCount;
				cout << *vi << " ";
			}
		}
		cout << endl;
		af = adjacent_find(af + nCount, iv.end());
	}

	cout << "median = " << iv[iv.size() / 2] << endl;
	float sum = accumulate(iv.begin(), iv.end(), 0);
	cout << "mean = " << (sum / iv.size()) << endl;
	int maxCount = 0;
	int maxVal = 0;
	for (int i : iv)
	{
		int iCount = count(iv.begin(), iv.end(), i);
		if (iCount > maxCount)
		{
			maxCount = iCount;
			maxVal = i;
		}
		i += iCount;
	}
	cout << "mode = " << maxVal << endl;

    return 0;
}

