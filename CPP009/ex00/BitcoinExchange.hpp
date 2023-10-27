/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amechain <amechain@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:58:18 by anoukmechai       #+#    #+#             */
/*   Updated: 2023/06/23 12:59:30 by amechain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_H
#define BITCOIN_EXCHANGE_H

# include <iostream>
# include <map>
#include <fstream>
#include <string>
#include <sys/stat.h>
#include <sstream>
#include <fstream>

class BitcoinExchange
{
	public :
		BitcoinExchange();
		BitcoinExchange( BitcoinExchange const & src);
		BitcoinExchange &operator=( BitcoinExchange const & src);
		~BitcoinExchange( void );

		std::ifstream* openFile(std::string filename);
		void parseLine(std::ifstream *infile, char flag);
		bool checkDate(std::string date);
		float checkValue(std::string valueStr, char flag);
		int getNumberOfDigits(int number);
		void checkGeneralFormat(std::string line, char flag);
		void findMatch(std::pair<std::string, float> pair);

	private :
		std::map<std::string, float> _bitcoin_rate;

};

#endif
