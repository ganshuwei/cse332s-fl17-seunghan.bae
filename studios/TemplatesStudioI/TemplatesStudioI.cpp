// TemplatesStudioI.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TemplatesStudioI.h"
#include <vector>

using namespace std;

int main(int argc, char * argv[])
{
	int arr[] = { 1, 2, 3, 3, 3 };
	vector<int> vec;
	vec.push_back(6);
	vec.push_back(7);
	vec.push_back(8);
	vec.push_back(9);
	cout << counter(arr, arr + 5) << endl;
	cout << counter(arr, arr + 5, 3) << endl;
	cout << counter(vec.begin(), vec.end()) << endl;
	cout << endl;

	MyStruct<int> msi(7);
	MyStruct<char> msc('s');
	cout << "sizeof(MyStruct<int>) = " << sizeof(msi) << endl;
	cout << "sizeof(int) = " << sizeof(int) << endl;
	cout << "sizeof(MyStruct<char>) = " << sizeof(msc) << endl;
	cout << "sizeof(char) = " << sizeof(char) << endl;
	cout << endl;

	cout << "MyStruct<int> msi(7) : " << msi << endl;
	cout << "MyStruct<char> msc('s') : " << msc << endl;
	cout << endl;

	MyStruct<int> msi2(10);
	MyStruct<int> msi3(1);
	MyStruct<int> msi4(7);

	cout << "7 == 10 : " << (msi == msi2) << endl;
	cout << "7 == 7 : " << (msi == msi4) << endl;
	cout << "1 < 10 : " << (msi3 < msi2) << endl;
	cout << "10 < 1 : " << (msi2 < msi3) << endl;
	cout << "7 < 7 : " << (msi < msi4) << endl;
	cout << endl;

	MyStruct<int> msii(msi);
	MyStruct<char> mscc = msc;
	cout << msii << endl;
	cout << mscc << endl;

	// MyStruct<int> msiii;
	// MyStruct<char> msccc;
	// cout << msiii << endl;
	// cout << msccc << endl;
	
	return 0;
}

