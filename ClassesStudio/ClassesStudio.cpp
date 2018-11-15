// ClassesStudio.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ClassesStudio.h"
#include <iostream>

using namespace std;

int main(int argc, char * argv[])
{
	TwoInts t;
	cout << "t.x = " << t.x() << " and t.y = " << t.y() << endl;
	t.x(7).y(3);
	cout << "t.x = " << t.x() << " and t.y = " << t.y() << endl;
	TwoInts s(t);
	cout << "s.x = " << s.x() << " and s.y = " << s.y() << endl;
	
	return 0;
}

TwoInts::TwoInts() : x_(0), y_(0)
{
}

TwoInts::TwoInts(const TwoInts &t) : x_(t.x_), y_(t.y_)
{
}

TwoInts::TwoInts(int x, int y) : x_(x), y_(y)
{
}

int TwoInts::x() const
{
	return x_;
}

int TwoInts::y() const
{
	return y_;
}

TwoInts & TwoInts::x(int newX)
{
	x_ = newX;

	return *this;
}

TwoInts & TwoInts::y(int newY)
{
	y_ = newY;

	return *this;
}
