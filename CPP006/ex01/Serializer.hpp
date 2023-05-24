#ifndef SERIALIZER_H
#define SERIALIZER_H

#include "Data.hpp"

# include <iostream>
# include <iomanip>
# include <string>

class Serializer
{
	public :
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

	private :
		static Serializer(); // try
		Serializer( Serializer const & src);
		Serializer &operator=( Serializer const & src);
		~Serializer( void );

};

#endif
