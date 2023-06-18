#ifndef BASE_H
#define BASE_H

class Base {

	public :
		virtual ~Base( void );
};

#endif

// Dynamic cast can only be applied
// to a class with one virtual function.
// Try without.

// what is header <typeinfo>