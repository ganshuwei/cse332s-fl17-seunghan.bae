// OverloadingStudio.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "OverloadingStudio.h"

using namespace std;

int main(int argc, char * argv[])
{
	OneInt o1;
	OneInt o2(10);
	OneInt o3(3);

	cout << o1 << " " << o2 << endl;

	cout << (o1 < o2) << endl;
	cout << (o2 < o3) << endl;
	cout << (o1 == o3) << endl;
	cout << o1 + (o2 + o3) << endl;

	OneInt o4 = o3;
	o1 = o2 = o3;

	cout << (o4 == o3) << endl;
	cout << o1 << " " << o2 << " " << o3 << " " << o4 << endl;

	cout << endl;

	TwoInts t1(1, 0);
	TwoInts t2(3, 2);

	cout << (t1 < t2) << endl;
	cout << (t1 == t2) << endl;
	TwoInts t3 = t1 + t2;
	cout << t3 << endl;

	cout << endl;
	cout << (o3 < t3) << endl;
	// cout << (t3 < o3) << endl;
	cout << (o4 == t2) << endl;
	// cout << (t2 == o4) << endl;
	cout << o3 + t3 << endl;
	// cout << t1 + o1 << endl;
	//TwoInts t4 = o3;
	OneInt o5 = t2;
	cout << o5 << endl;
	
	
	return 0;
}

OneInt::OneInt(int n) : n_(n)
{
}

const bool OneInt::operator<(const OneInt & o)
{
	return n_ < o.n_;
}

const bool OneInt::operator==(const OneInt & o)
{
	return n_ == o.n_;
}

const OneInt OneInt::operator+(const OneInt & o)
{
	return OneInt(n_ + o.n_);
}

OneInt & OneInt::operator=(const OneInt & o)
{
	n_ = o.n_;
	return *this;
}

ostream & operator<<(ostream & os, const OneInt & o)
{
	os << o.n_;
	return os;
}

TwoInts::TwoInts(int n, int m) : OneInt(n), m_(m)
{
}

const bool TwoInts::operator<(const TwoInts & t)
{
	return (n_ + m_) < (t.n_ + t.m_);
}

const bool TwoInts::operator==(const TwoInts & t)
{
	return (n_ == t.n_) && (m_ == t.m_);
}

const TwoInts TwoInts::operator+(const TwoInts & t)
{
	return TwoInts(n_ + t.n_, m_ + t.m_);
}

TwoInts & TwoInts::operator=(const TwoInts & t)
{
	n_ = t.n_;
	m_ = t.m_;
	return *this;
}

ostream & operator<<(ostream & os, const TwoInts & t)
{
	os << "(" << t.n_ << "," << t.m_ << ")";
	return os;
}
