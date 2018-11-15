#ifndef OVERLOADING_STUDIO_H
#define OVERLOADING_STUDIO_H

#include <iostream>

class OneInt
{
	friend std::ostream & operator<<(std::ostream &, const OneInt &);
public:
	OneInt(int n = 0);
	
	const bool operator<(const OneInt &);
	const bool operator==(const OneInt &);
	const OneInt operator+(const OneInt &);
	OneInt & operator=(const OneInt &);
protected:
	int n_;
};

class TwoInts : public OneInt
{
	friend std::ostream & operator<<(std::ostream &, const TwoInts &);
public:
	TwoInts(int n = 0, int m = 0);

	const bool operator<(const TwoInts &);
	const bool operator==(const TwoInts &);
	const TwoInts operator+(const TwoInts &);
	TwoInts & operator=(const TwoInts &);
private:
	int m_;
};

std::ostream & operator<<(std::ostream &, const OneInt &);
std::ostream & operator<<(std::ostream &, const TwoInts &);

#endif /* OVERLOADING_STUDIO_H */s
