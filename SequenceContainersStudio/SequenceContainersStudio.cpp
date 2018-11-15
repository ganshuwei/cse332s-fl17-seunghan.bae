// SequenceContainersStudio.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <array>

using namespace std;

void vectorIter(const vector<int> & v)
{
	for (vector<int>::const_iterator ci = v.cbegin(); ci != v.cend(); ++ci)
	{
		cout << *ci << " ";
	}
}

int main(int argc, char * argv[])
{
	vector<int> v;
	deque<int> d;
	list<int> l;
	forward_list<int> fl;
	string s;

	s.push_back('a');
	s.push_back('b');
	s.push_back('c');
	for (string::iterator i = s.begin(); i != s.end(); ++i)
	{
		cout << *i << endl;
	}
	for (int y = 0; y < s.size(); ++y)
	{
		cout << s[y] << endl;
	}


	v.emplace_back(1);
	v.push_back(2);
	v.push_back(3);
	// vectorIter(v);
	for (unsigned int x1 = 0; x1 < v.size(); ++x1)
	{
		cout << v[x1];
	}
	cout << endl;

	d.emplace_back(1);
	d.push_back(2);
	d.push_back(3);
	d.push_front(3);
	d.emplace_front(2);
	d.push_front(1);
	for (deque<int>::iterator i2 = d.begin(); i2 != d.end(); ++i2)
	{
		cout << *i2 << " ";
	}
	/*for (unsigned int x2 = 0; x2 < d.size(); ++x2)
	{
		cout << d[x2];
	}*/
	cout << endl;

	l.emplace_back(1);
	l.push_back(2);
	l.push_back(3);
	// l.push_front(3);
	// l.push_front(2);
	// l.push_front(1);
	for (list<int>::iterator i3 = l.begin(); i3 != l.end(); ++i3)
	{
		cout << *i3 << " ";
	}
	/*for (unsigned int x3 = 0; x3 < l.size(); ++x3)
	{
		cout << l[x3] << endl;
	}*/
	cout << endl;

	fl.emplace_front(3);
	fl.push_front(2);
	fl.push_front(1);
	for (forward_list<int>::iterator i4 = fl.begin(); i4 != fl.end(); ++i4)
	{
		cout << *i4 << " ";
	}
	/*for (unsigned int x4 = 0; x4 < fl.size(); ++x4)
	{
		cout << fl[x4] << endl;
	}*/
	cout << endl;

	// none of the below works
	/*vector<int> vd(d);
	vector<int> vl(l);
	vector<int> vfl(fl);

	deque<int> dv(v);
	deque<int> dl(l);
	deque<int> dfl(fl);

	list<int> lv(v);
	list<int> ld(d);
	list<int> lfl(fl);

	forward_list<int> flv(v);
	forward_list<int> fld(d);
	forward_list<int> fll(l);*/
	
	return 0;
}
