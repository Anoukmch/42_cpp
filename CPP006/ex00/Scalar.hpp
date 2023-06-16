#ifndef SCALAR_H
#define SCALAR_H

# include <iostream>
# include <iomanip>
# include <string>

class ScalarConverter
{
	public :

		static void convert(std::string const& input);
		static bool isInt(std::string const& input);
		static bool isImpossible(std::string input);
		static bool isOnlyDigits(std::string const& input);
		static void printer(void);

		static int _int;

	private :
		static int _int;
		static char _char;
		static float _float;
		static double _double;

		ScalarConverter();
		ScalarConverter( ScalarConverter const & src);
		ScalarConverter &operator=( ScalarConverter const & src);
		~ScalarConverter( void );

};

#endif
