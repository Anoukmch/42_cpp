/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukmechain <anoukmechain@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:00:11 by anoukmechai       #+#    #+#             */
/*   Updated: 2023/06/16 11:32:02 by anoukmechai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	parseLine(openFile("./data.csv"), ',');
}

BitcoinExchange::BitcoinExchange( BitcoinExchange const & src) {
	*this = src;
}

// Destructors
BitcoinExchange::~BitcoinExchange( void ) {
}

// Operator overload
BitcoinExchange & BitcoinExchange::operator=( BitcoinExchange const & src) { 
	if ( this != &src ) {
		_bitcoin_rate = src._bitcoin_rate;
	}
	return ( *this );
}

void BitcoinExchange::checkGeneralFormat(std::string line, char flag)
{
	/* try if (issValue >> valeue) (Type of extraction method) */
	int arg;
	char del;
	int bytesRead = 0;
	// CHECK SPACE, IT IS NOT WORKING
	arg = sscanf(line.c_str(), "%*d-%*d-%*d%c%*f%n", &del, &bytesRead);  // What about multiple space, does it skip it ?
	std::cout << "bye read " << bytesRead << std::endl;
	if (arg != 1 || (flag == ',' && del != ',') || (flag == '|' && del != '|') || (int)line.size() != bytesRead) // line[bytesRead] maybe it's a space 
		throw std::logic_error("Wrong input format");
}

std::ifstream BitcoinExchange::openFile(std::string filename)
{
	std::ifstream infile(filename); // std::ifstream C++98 ? 
	struct stat s;
	
	if (stat(filename.c_str(), &s) != 0 || (s.st_mode & S_IFDIR) != 0)
		throw std::runtime_error("Wrong file format");
		
	if (!infile.is_open())
		throw std::runtime_error("Could not open file");
		
	return (infile);
}

void BitcoinExchange::parseLine(std::ifstream infile, char flag)
{
	std::string line;
	
	std::getline(infile, line);
	if ((flag == ',' && line != "date,exchange_rate") 
		|| (flag == '|' && line != "date | value"))
		throw std::logic_error("Wrong header in file"); 

    while (std::getline(infile, line))
	{
		try
		{
			std::istringstream iss(line);
   			std::string date, valueStr;

			std::getline(iss, date, flag);
			std::getline(iss, valueStr);

			checkGeneralFormat(line, flag);
			checkDate(date);
			float value = checkValue(valueStr, flag);
			if (flag == ',')
				_bitcoin_rate.insert(std::make_pair(date, value));
			if (flag == '|')
				findMatch(std::make_pair(date, value));
		}
		catch(const std::exception& e) { std::cerr << "Error: " << e.what() << '\n';}		
    }
	infile.close();
}

void BitcoinExchange::findMatch(std::pair<std::string, float> pair)
{
	std::map<std::string, float>::iterator it = _bitcoin_rate.lower_bound(pair.first);	
	if (it == _bitcoin_rate.begin())
		throw std::runtime_error("The database is too recent to collect this value ");
	if (it == _bitcoin_rate.end() || it->first != pair.first) 
		--it;
	std::cout << pair.first << " => " << pair.second << " = " << pair.second * it->second << std::endl;	
}

int BitcoinExchange::getNumberOfDigits(int number)
{
    std::ostringstream oss;
    oss << number;
    std::string numberString = oss.str();
    return numberString.length();
}

bool	BitcoinExchange::checkDate(std::string date)
{
	int year; 
	int month; 
	int day; 

	int arg = sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
	if (arg != 3 || getNumberOfDigits(year) != 4 || month > 12 || month <= 0 || day <= 0 || day > 31)
		throw std::logic_error("Wrong date format");
	if (month == 2 && day > 29)
		throw std::logic_error("Wrong date format");
	if ((month == 4 || month == 6 || month == 9 || month == 11) && (day > 30))
		throw std::logic_error("Wrong date format");
	return (0);
}

float	BitcoinExchange::checkValue(std::string valueStr, char flag)
{
	float value;

	int arg = sscanf(valueStr.c_str(), "%f", &value); // try value as e.g. "3 f" or try a null string 
	
	/* OR...
			std::istringstream issValue(valueStr);
        	float value;
        	if (issValue >> value)
				std::cout << value << std::endl;
	*/
	if (arg != 1)
		throw std::logic_error("Wrong value format");

	if (flag == '|' && (value < 0 || value > 1000))
		throw std::logic_error("Value out-of-range");		
	else if (flag == ',' && value < 0)
		throw std::logic_error("Value out-of-range");
	return (value);
}

// Either I put the wrong input in the file and mark them as wrong 
// Either I reject them but then complicated for output order

// infile.close();