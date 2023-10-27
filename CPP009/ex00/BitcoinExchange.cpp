/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:00:11 by anoukmechai       #+#    #+#             */
/*   Updated: 2023/06/23 16:26:58 by amechain         ###   ########.fr       */
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

std::string trim(const std::string& str)
{
    std::size_t start = str.find_first_not_of(" \t\n\r\f");
    if (start == std::string::npos) {
        return "";
    }

    std::size_t end = str.find_last_not_of(" \t\n\r\f");

    return str.substr(start, end - start + 1);
}

void BitcoinExchange::checkGeneralFormat(std::string line, char flag)
{
	int arg;
	char del;
	int bytesRead = 0;

	if (flag == '|')
	{
		for (size_t i = 0; i < line.size() ; i++)
		{
			if ((line[i] == ' ' && line[i + 1] != '|')
				&& (line[i] == ' ' && line[i - 1] != '|'))
				throw std::logic_error("Wrong input format");
		}
	}

	arg = sscanf(line.c_str(), "%*d-%*d-%*d %c %*f%n", &del, &bytesRead);

	if (arg != 1 || (flag == ',' && del != ',') || (flag == '|' && del != '|') || (int)line.size() != bytesRead)
		throw std::logic_error("Wrong input format");
}

std::ifstream* BitcoinExchange::openFile(std::string filename)
{
	std::ifstream* infile = new std::ifstream(filename);
	struct stat s;

	if (stat(filename.c_str(), &s) != 0 || (s.st_mode & S_IFDIR) != 0)
		throw std::runtime_error("Wrong file format or missing file : check input AND database files");

	if (!infile->is_open())
		throw std::runtime_error("Could not open file");

	return (infile);
}

void BitcoinExchange::parseLine(std::ifstream *infile, char flag)
{
	std::string line;

	std::getline(*infile, line);
	if ((flag == ',' && line != "date,exchange_rate")
		|| (flag == '|' && line != "date | value"))
		throw std::logic_error("Wrong header in file");

    while (std::getline(*infile, line))
	{
		try
		{
			if (line.empty())
				throw std::logic_error("string empty ");
			std::istringstream iss(line);
   			std::string date, valueStr;

			std::getline(iss, date, flag);
			std::getline(iss, valueStr);

			checkGeneralFormat(line, flag);
			checkDate(date);
			float value = checkValue(valueStr, flag);
			if (flag == ',')
				_bitcoin_rate.insert(std::make_pair(trim(date), value));
			if (flag == '|')
				findMatch(std::make_pair(trim(date), value));
		}
		catch(const std::exception& e) { std::cerr << "Error: " << e.what() << " => " << trim(line) << '\n';}
    }
	(*infile).close();
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

	int arg = sscanf(valueStr.c_str(), "%f", &value);

	if (arg != 1)
		throw std::logic_error("Wrong value format");

	if (flag == '|' && (value < 0 || value > 1000))
		throw std::logic_error("Value out-of-range");
	else if (flag == ',' && value < 0)
		throw std::logic_error("Value out-of-range");
	return (value);
}
