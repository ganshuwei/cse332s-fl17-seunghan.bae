// DynamicMemoryStudio.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Detector.h"
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

shared_ptr<detector> func(shared_ptr<detector> spd)
{
	cout << "beginning of fn" << endl;

	cout << "end of fn" << endl;
	return spd;
}

int main()
{
	cout << "beginning" << endl;

	shared_ptr<detector> spd = make_shared<detector>();
	shared_ptr<detector> spd2 = func(spd);
	shared_ptr<detector> spd3 = make_shared<detector>();
	shared_ptr<detector> spd4 = make_shared<detector>();
	shared_ptr<detector> spd5 = make_shared<detector>();

	vector<shared_ptr<detector>> v;
	v.push_back(spd);
	v.push_back(spd2);
	v.push_back(spd3);
	v.push_back(spd4);
	v.push_back(spd5);

	cout << &*spd << " " << &*spd2 << " " << &*spd3 << " " << &*spd4 << " " << &*spd5 << endl;
	cout << &*v[0] << " " << &*v[1] << " " << &*v[2] << " " << &*v[3] << " " << &*v[4] << endl;

	cout << "end" << endl;
	return 0;
}

