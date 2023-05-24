#include "Scalar.hpp"

ScalarConverter::ScalarConverter() : _char(0), _int(0), _float(0), _double(0) {}

ScalarConverter::ScalarConverter( ScalarConverter const & src) {
	*this = src;
}

// Destructors
ScalarConverter::~ScalarConverter( void ) {
}

// Operator overload
ScalarConverter & ScalarConverter::operator=( ScalarConverter const & src) {
	if ( this != &src ) {
		_char = src._char;
		_int = src._int;
		_float = src._float;
		_double = src._double;
	}
	return ( *this );
}

char ScalarConverter::getChar(void) const { return _char; }
int ScalarConverter::getInt(void) const { return _int; }
float ScalarConverter::getFloat(void) const { return _float; }
double ScalarConverter::getDouble(void) const { return _double; }

bool ScalarConverter::isImpossible(std::string input)
{
	std::string pseudoLiterals[8] = { "inf", "+inf", "inff", "+inff", "-inf", "-inff", "nan", "nanf" };
	for (int i = 0 ; i < 8 ; i++)
		if (input == pseudoLiterals[i])
		{
			if (pseudoLiterals[i][0] == '-')
			{
				_double = (-1) * std::numeric_limits<double>::infinity();
				_float = (-1) * std::numeric_limits<float>::infinity();
				return (true);
			}
			else if (pseudoLiterals[i][0] == 'n')
			{
				_double = std::numeric_limits<double>::quiet_NaN();
				_float = std::numeric_limits<float>::quiet_NaN();
				return (true);
			}
			else
			{
				_double = std::numeric_limits<double>::infinity();
				_float = std::numeric_limits<float>::infinity();
				return (true);
			}
		}
		return (false);
}

bool ScalarConverter::isInt(std::string const& input)
{
	char *end;
	long nb = std::strtol(input.c_str(), &end, 10);

	if (*end != '\0' || nb > INT_MAX || nb < INT_MIN)
		return (false);
	return (true);
}

bool hasDuplicate(const std::string& input, char targetChar)
{
    for (std::size_t i = 0; i < input.length(); ++i)
	{
        if (input[i] == targetChar)
		{
            for (std::size_t j = i + 1; j < input.length(); ++j)
			{
                if (input[j] == targetChar)
                    return (true);
            }
        }
    }
    return (false);
}

bool ScalarConverter::isOnlyDigits(std::string const& input) {
	if ((input[0] == '+' || input[0] == '-') && !std::isdigit(input[1]))
			return (false);
    for (size_t i = 0; i < input.length(); ++i) // Check why i = 0 with ++i
	{
        if (!std::isdigit(input[i]) && input[i] != 'f' && input[i] != '.')
            return (false);
		if (hasDuplicate(input, 'f') || hasDuplicate(input, '.'))
			return (false);
    }
    return (true);
}

void ScalarConverter::convert(std::string const& input) // Store non-sense value in char and int ? Don't make sense
{
	if (isImpossible(input))
		return ;
	else if (input.size() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]))
	{
		_char = input[0];
		_int = static_cast<int>(_char);
		_double = static_cast<double>(_char);
		_float = static_cast<float>(_char);
	}
	else if (input[input.length() - 1] == 'f' && isOnlyDigits(input))
	{
		_float = std::atof(input.c_str());
		_char = static_cast<char>(_float);
		_int = static_cast<int>(_float);
		_double = static_cast<double>(_float);

	}
	else if (input.find('.') != std::string::npos && isOnlyDigits(input)
		&& input.find('f') == std::string::npos)
	{
		_double = std::atof(input.c_str());
		_char = static_cast<char>(_double);
		_int = static_cast<int>(_double);
		_float = static_cast<float>(_double);
	}
	else if (isInt(input) && isOnlyDigits(input))
	{
		_int = std::atoi(input.c_str());
		_char = static_cast<int>(_int);
		_float = static_cast<float>(_int);
		_double = static_cast<double>(_int);
	}
	else
		throw WrongInput();
}

std::ostream &operator<<( std::ostream &flux, ScalarConverter const& var ) {
	flux << "char : ";
	if ( var.getInt() > CHAR_MAX || var.getInt() < CHAR_MIN
		|| var.getFloat() > CHAR_MAX || var.getFloat() < CHAR_MIN
		|| var.getDouble() > CHAR_MAX || var.getDouble() < CHAR_MIN
		|| isnan(var.getFloat()))
		flux << "impossible" << std::endl;
	else if (!std::isprint(var.getInt()))
		flux << "not displayable" << std::endl;
	else
		flux << var.getChar() << std::endl;

	flux << "int : ";
	if ( var.getFloat() > INT_MAX || var.getFloat() < INT_MIN
		|| var.getDouble() > INT_MAX || var.getDouble() < INT_MIN
		|| isnan(var.getFloat()))
		flux << "impossible" << std::endl;
	else
		flux << var.getInt() << std::endl;

	if (var.getFloat() == static_cast<int>(var.getFloat()))
		flux << "float : " << std::fixed << std::setprecision(1) << var.getFloat() << "f" << std::endl;
	else
		flux << "float : " << var.getFloat() << "f" << std::endl;

	flux << "double : " << var.getDouble() << std::endl;
	return ( flux );
}

const char* ScalarConverter::WrongInput::what() const throw()
{
	return ("-> The input is not valid : please send a literal (char, int, double, float)");
}
