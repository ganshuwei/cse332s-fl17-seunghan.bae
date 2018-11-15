#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>

struct TwoInts {
	TwoInts();
	TwoInts(const TwoInts &);
	TwoInts(int x, int y);

	int x() const;
	int y() const;

	TwoInts & x(int);
	TwoInts & y(int);

	int x_;
	int y_;
};

std::istream & operator >> (std::istream &, TwoInts &);
std::ostream & operator << (std::ostream &, const TwoInts &);

#endif /* CLASSES_H */
