#ifndef SCALAR_H
#define SCALAR_H

# include <iostream>
# include <iomanip>
# include <string>

class ScalarConverter
{
	public :
		ScalarConverter();
		ScalarConverter( ScalarConverter const & src);
		ScalarConverter &operator=( ScalarConverter const & src);
		~ScalarConverter( void );

		void convert(std::string const& input);
		bool isInt(std::string const& input);
		bool isImpossible(std::string input);
		bool isOnlyDigits(std::string const& input);

		char getChar(void) const;
		int getInt(void) const;
		float getFloat(void) const;
		double getDouble(void) const;

		class WrongInput : public std::exception {
			public:
				virtual const char* what() const throw();
		};

	private :
		char _char;
		int _int;
		float _float;
		double _double;

};

std::ostream &operator<<( std::ostream &flux, ScalarConverter const& var);

#endif
