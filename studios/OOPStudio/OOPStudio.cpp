// OOPStudio.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Classes.h"
#include <iostream>

using namespace std;

void meth(A a)
{
	a.func();
}

void meth(B b)
{
	b.func();
}

void methRef(A & a)
{
	a.func();
}

void methRef(B & b)
{
	b.func();
}

int main()
{
	// 1-4, 6
	A a;
	B b;
	// A & r1 = a;
	// A & r2 = b;
	// B & r3 = b;
	A * r1 = &a;
	A * r2 = &b;
	B * r3 = &b;

	cout << endl;

	cout << "A a;" << endl;
	a.func();
	meth(a);
	methRef(a);
	cout << endl;

	cout << "B b;" << endl;
	b.func();
	meth(b);
	methRef(b);
	cout << endl;

	// cout << "A & r1 = a;" << endl;
	cout << "A * r1 = &a;" << endl;
	// r1.func();
	r1->func();
	meth(*r1);
	methRef(*r1);
	cout << endl;

	// cout << "A & r2 = b;" << endl;
	cout << "A * r2 = &b;" << endl;
	// r2.func();
	r2->func();
	meth(*r2);
	methRef(*r2);
	cout << endl;

	// cout << "B & r3 = b;" << endl;
	cout << "B * r3 = &b;" << endl;
	// r3.func();
	r3->func();
	meth(*r3);
	methRef(*r3);
	cout << endl;


	/* 5
	cout << "p1 : A" << endl;
	A * p1 = new A;
	cout << endl;

	cout << "p2: B" << endl;
	A * p2 = new B;
	cout << endl;

	cout << "p3: B" << endl;
	B * p3 = new B;
	cout << endl;

	cout << "delete p1" << endl;
	delete p1;
	cout << endl;

	cout << "delete p2" << endl;
	delete p2;
	cout << endl;

	cout << "delete p3" << endl;
	delete p3;
	cout << endl; */

	return 0;
}

