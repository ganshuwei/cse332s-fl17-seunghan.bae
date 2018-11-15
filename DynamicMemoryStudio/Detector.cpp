#include "stdafx.h"
#include "Detector.h"
#include <iostream>

using namespace std;

detector::detector() : x_(y_)
{
	++y_;
	cout << "detector() " << this << " x=" << x_ << endl;
}

detector::~detector()
{
	cout << "~detector() " << this << " x=" << x_ << endl;
}

unsigned int detector::x() const
{
	return x_;
}

unsigned int detector::y_ = 0;
