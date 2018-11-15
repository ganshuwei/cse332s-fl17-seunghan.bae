#ifndef DESIGN_PATTERNS_STUDIO_H
#define DESIGN_PATTERNS_STUDIO_H

#include <iostream>
#include <iterator>
#include <list>

struct Animal
{
	virtual void print(std::ostream &) const = 0;
	virtual Animal * clone() = 0;
};

struct Giraffe : public Animal
{
	virtual void print(std::ostream &) const;
	void look();
	Animal * clone();
};

struct Ostrich : public Animal
{
	virtual void print(std::ostream &) const;
	void hide();
	Animal * clone();
};

class Zoo
{
	friend std::ostream & operator<<(std::ostream &, const Zoo &);
public:
	Zoo(const Zoo &);
	~Zoo();

	static Zoo * instance();
	void add(Animal *);
	void observe();
private:
	Zoo()
	{
		flag_ = false;
		std::cout << "a zoo has been created" << std::endl;
	}
	Zoo & operator=(const Zoo &);

	std::list<Animal *> la_;
	static Zoo * zoo_;
	bool flag_;
};

std::ostream & operator<<(std::ostream &, const Zoo &);

template<typename T>
void print(T & t, std::ostream & os)
{
	for (T::const_iterator i = t.cbegin(); i != t.cend(); ++i)
	{
		(*i)->print(os);
	}
}

#endif /* DESIGN_PATTERNS_STUDIO_H */
