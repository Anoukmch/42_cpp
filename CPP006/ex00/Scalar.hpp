#ifndef SCALAR_H
#define SCALAR_H

# include <iostream>

class ScalarConverter
{
	public :
		ScalarConverter();
		ScalarConverter( ScalarConverter const & src);
		ScalarConverter &operator=( ScalarConverter const & src);
		~ScalarConverter( void );

		void convert(std::string const& input);
		void	printer(void);
		void	isInt(std::string const& input);
		void	isFloat(std::string const& input);
		void	isChar(std::string const& input);
		void	isDouble(std::string const& input);

	private :
		char _char;
		int _int;
		float _float;
		double _double;

};

#endif
