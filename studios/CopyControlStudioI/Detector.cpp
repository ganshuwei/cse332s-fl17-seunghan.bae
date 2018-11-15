#include "stdafx.h"
#include "Detector.h"
#include <iostream>

using namespace std;

detector::detector() : x_(y_)
{
	++y_;
	cout << "detector() " << this << " x=" << x_ << endl;
}

detector::detector(const detector & d) : x_(d.x_)
{
	cout << "detector(copy) " << this << " x=" << x_ << endl;
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

wrapper::wrapper() : d_(0), b_(true)
{
	d_ = new detector;
	cout << this << endl;
}

wrapper::wrapper(const wrapper & w) : d_(w.d_), b_(false)
{
	// d_ = new detector(*w.d_);
	// cout << this << endl;
}

wrapper::~wrapper()
{
	delete d_;
	cout << this << endl;

}
