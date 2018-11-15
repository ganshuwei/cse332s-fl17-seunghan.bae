// DesignPatternsStudio.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DesignPatternsStudio.h"
#include <vector>

using namespace std;

int main(int argc, char * argv[])
{
	Giraffe g;
	Ostrich o;

	/* vector<Animal *> vtr;
	vtr.push_back(&g);
	vtr.push_back(&o);

	list<Animal *> lst;
	lst.push_back(&g);
	lst.push_back(&o);

	print(vtr, cout);
	print(lst, cout); */
	
	Zoo * z = Zoo::instance();
	z->add(&g);
	z->add(&o);

	cout << *z << endl;

	z->observe();

	Zoo z2(*z);
	cout << *z << endl;
	cout << z2 << endl;

}

void Giraffe::print(ostream & os) const
{
	os << "Giraffe" << endl;
}

void Giraffe::look()
{
	cout << "giraffe is looking around, can see far away" << endl;
}

Animal * Giraffe::clone()
{
	Giraffe * gPtr = new Giraffe(*this);
	return gPtr;
}

void Ostrich::print(ostream & os) const
{
	os << "Ostrich" << endl;
}

void Ostrich::hide()
{
	cout << "ostrich has buried its head in the sand, cannot see anything" << endl;
}

Animal * Ostrich::clone()
{
	Ostrich * oPtr = new Ostrich(*this);
	return oPtr;
}

Zoo::Zoo(const Zoo & z) : la_(), flag_(false)
{
	for (list<Animal *>::const_iterator i = z.la_.cbegin(); i != z.la_.cend(); ++i)
	{
		Animal * a = (*i)->clone();
		la_.push_back(a);
	}
	flag_ = true;
}

Zoo::~Zoo()
{
	if (flag_ == true)
	{
		for (list<Animal *>::iterator i = la_.begin(); i != la_.end(); ++i)
		{
			delete (*i);
		}
	}
}

Zoo * Zoo::instance()
{
	if (zoo_ == 0)
	{
		zoo_ = new Zoo;
	}

	return zoo_;
}

void Zoo::add(Animal * a)
{
	la_.push_back(a);
}

void Zoo::observe()
{
	for (list<Animal *>::iterator i = la_.begin(); i != la_.end(); ++i)
	{
		Giraffe * gPtr = dynamic_cast<Giraffe *>(*i);
		if (gPtr != 0)
		{
			gPtr->look();
		}
		Ostrich * oPtr = dynamic_cast<Ostrich *>(*i);
		if (oPtr != 0)
		{
			oPtr->hide();
		}
	}
}

Zoo * Zoo::zoo_ = 0;

std::ostream & operator<<(std::ostream & os, const Zoo & z)
{
	print(z.la_, os);
	return os;
}
