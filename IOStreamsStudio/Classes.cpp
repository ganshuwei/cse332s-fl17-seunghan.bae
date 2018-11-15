// Classes.cpp
//

#include "stdafx.h"
#include "Classes.h"

using namespace std;

TwoInts::TwoInts() : x_(0), y_(0)
{
}

TwoInts::TwoInts(const TwoInts &t) : x_(t.x_), y_(t.y_)
{
}

TwoInts::TwoInts(int x, int y) : x_(x), y_(y)
{
}

istream & operator >> (istream & is, TwoInts & t)
{
	is >> t.x_ >> t.y_;
	return is;
}

ostream & operator << (ostream & os, const TwoInts & t)
{
	os << t.x_ << " " << t.y_;
	return os;
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
