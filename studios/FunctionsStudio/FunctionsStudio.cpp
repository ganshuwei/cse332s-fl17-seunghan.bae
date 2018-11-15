// FunctionsStudio.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "FunctionsStudio.h"
#include <iostream>

using namespace std;

int main()
{
	/*unsigned int ans;

	factorial(3, &ans);
	cout << ans << endl;
	factorial(6, &ans);
	cout << ans << endl;
	factorial(1, &ans);
	cout << ans << endl;
	factorial(10, &ans);
	cout << ans << endl;*/

	/*cout << power() << endl;
	cout << power(2, 3) << endl;
	cout << power(4, 0) << endl;
	cout << power(2) << endl;*/

	// unsigned int arr[4] = { 1, 2, 3, 4 };
	unsigned int ptr = 3;
	arrayFunc(4, &ptr);
	cout << ptr << endl;

    return 0;
}

// unsigned int factorial(unsigned int num)
void factorial(unsigned int num, unsigned int * ans)
{
	/*unsigned int ans = 1;
	for (unsigned int i = 1; i <= num; ++i)
	{
		ans *= i;
	}
	return ans;*/

	if (num <= 1)
	{
		// return 1;
		*ans = 1;
	}
	else
	{
		// return num * factorial(num - 1);
		factorial(num - 1, ans);
		*ans *= num;
	}
}

unsigned int power(unsigned int x, unsigned int y)
{
	if (y <= 0)
	{
		return 1;
	}
	else
	{
		return x * power(x, y - 1);
	}
}

void arrayFunc(size_t length, unsigned int * ptr)
{
	*ptr = 5;
}

