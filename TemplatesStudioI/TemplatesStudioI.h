#ifndef TEMPLATES_STUDIO_I_H
#define TEMPLATES_STUDIO_I_H

#include <iostream>

template <typename Iterator>
size_t counter(Iterator first, Iterator last)
{
	size_t s = 0;
	while (first != last)
	{
		++s;
		++first;
	}
	return s;
}

template <typename Iterator, typename T>
size_t counter(Iterator first, Iterator last, T t)
{
	size_t s = 0;
	while (first != last)
	{
		if (*first == t)
		{
			++s;
		}
		++first;
	}
	return s;
}

template <typename T>
class MyStruct
{
	template <typename T>
	friend std::ostream & operator<<(std::ostream & os, const MyStruct<T> & ms);
public:
	// MyStruct() {}
	MyStruct(const T & t) : t_(t)
	{
	}
	bool operator==(const MyStruct<T> & ms)
	{
		return (t_ == ms.t_);
	}
	bool operator<(const MyStruct<T> & ms)
	{
		return (t_ < ms.t_);
	}
private:
	T t_;
};

template <typename T>
std::ostream & operator<<(std::ostream & os, const MyStruct<T> & ms)
{
	os << ms.t_;
	return os;
}

#endif /* TEMPLATES_STUDIO_I_H */
