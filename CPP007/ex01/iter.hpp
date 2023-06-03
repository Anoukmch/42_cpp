#ifndef EX00_H
#define EX00_H

# include <iostream>
# include <iomanip>
# include <string>

template <typename A, typename B>
void	iter(A * array, int length, B f)
{
	for (int i = 0 ; i < length ; i++)
		f(array[i]);
}

template <typename T>
void	plus(T nbr)
{
	nbr += 1;
}

#endif
