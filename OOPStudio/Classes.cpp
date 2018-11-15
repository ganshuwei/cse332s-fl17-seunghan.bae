#include "stdafx.h"
#include "Classes.h"
#include <iostream>

using namespace std;

A::A()
{
	cout << "A() ";
}

A::~A()
{
	cout << "~A() ";
}

void A::func()
{
	cout << "A::func() ";
}

B::B() : A()
{
	cout << "B() ";
}

B::~B()
{
	cout << "~B() ";
}

void B::func()
{
	cout << "B::func() ";
}
