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
		Serializer();
		Serializer( Serializer const & src);
		Serializer &operator=( Serializer const & src);
		~Serializer( void );

};

std::ostream &operator<<( std::ostream &flux, Data const& var );

#endif
