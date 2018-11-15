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

wrapper::wrapper() : d_(0)
{
	d_ = new detector;
}

wrapper::wrapper(const wrapper & w) : d_(0)
{
	// cout << detector::y_ << endl;
	cout << "copy" << endl;
	d_ = new detector(*w.d_);
	// cout << detector::y_ << endl;
}

wrapper::wrapper(wrapper && w) : d_(w.d_)
{
	cout << "move" << endl;
	w.d_ = nullptr;
}

wrapper::~wrapper()
{
	delete d_;
}

wrapper & wrapper::operator=(const wrapper & w)
{
	// cout << detector::y_ << endl;
	if (&w != this)
	{
		wrapper temp(w);
		swap(temp.d_, d_);
	}
	// cout << detector::y_ << endl;
	return *this;
}

wrapper & wrapper::operator=(wrapper && w)
{
	if (&w != this)
	{
		delete d_;
		d_ = w.d_;
		w.d_ = nullptr;
	}
	return *this;
}
