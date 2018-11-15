#ifndef TEMPLATES_STUDIO_II_H
#define TEMPLATES_STUDIO_II_H

#include <iostream>

template <typename Iterator>
size_t counter(Iterator first, Iterator second)
{
	std::cout << "++ implementation" << std::endl;

	size_t s = 0;
	while (first != second)
	{
		++s;
		++first;
	}
	return s;
}

/*template <typename Iterator>
size_t counter(Iterator * first, Iterator * second)
{
	std::cout << "ptr implementation" << std::endl;
	
	return (second - first);
}*/

template <> size_t counter(int * i1, int * i2)
{
	std::cout << "int ptr implementation" << std::endl;

	size_t s = 0;
	while (i1 != i2)
	{
		std::cout << *i1 << " ";
		++s;
		++i1;
	}
	std::cout << std::endl;

	return s;
}

/*template <> size_t counter(char * c1, char * c2)
{
	std::cout << "char ptr implementation" << std::endl;

	size_t s = 0;
	while (c1 != c2)
	{
		std::cout << *c1;
		++s;
		++c1;
	}
	std::cout << std::endl;

	return s;
}*/

#endif /* TEMPLATES_STUDIO_II_H */
