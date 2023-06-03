#ifndef EX00_H
#define EX00_H

# include <iostream>
# include <iomanip>
# include <string>

template <typename T>
void	swap(T &a, T &b)
{
	T buf;

	buf = a;
	a = b;
	b = buf;
}

template <typename T>
T const &	min(T &a, T &b)
{
	if (a < b)
		return (a);
	return (b);
}

template <typename T>
T const &	max(T &a, T &b)
{
	if (a > b)
		return (a);
	return (b);
}

#endif
