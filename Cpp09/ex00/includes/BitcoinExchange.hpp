/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:44:02 by hrobin            #+#    #+#             */
/*   Updated: 2024/04/15 19:45:27 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

// #define NEGATIVE_ERR			"not a positive number."
// #define TOO_LARGE_ERR			"too large a number."
#define BAD_INPUT_ERR			"bad input => "
// #define	INVALID_DB_ERR			"invalid database"
// #define WRONG_DATE_ERR			"no data for this date."
#define INVALID_DATE_ERR		"bad date format => "
// #define COULD_NOT_OPEN_ERR		"could not open file."
// #define INV_ARG_NUMBER_ERR		"invalid number of arguments."

#define SEPARATORS			"|"
#define DB_SEPARATORS		","

class BitcoinExchange
{
	public :

		BitcoinExchange(){}
		BitcoinExchange( const int ac, const char *fileName )
		{
			if (ac != 2)
        		throw BitcoinExchange::WrongArgNb();
    		SetData();
    		SetFile(fileName);
			// std::cout << "an instance of BitcoinExchange has been created." << std::endl;
		}
		BitcoinExchange( const BitcoinExchange &bigcoinExchange );
		BitcoinExchange &operator=( const BitcoinExchange &bigcoinExchange );
		~BitcoinExchange(){
			// std::cout << "an instance of BitcoinExchange has been destroyed" << std::endl;
   			}

		void SetData();
		void SetFile(const char *filename);
		void StructureData();
		void processDataMapEntry(const std::string line);
		void validateDateInput(const std::string &date) const;
		void processAndDisplay();
		void processLine(const std::string& line) const;
		void validateValue(const float value) const;
		std::string findNearestDate(const std::map<std::string, float>& myMap, const std::string& input) const;

		class WrongArgNb: public std::exception
		{
			public :
				const char *what() const throw();
		};
		class InvalidFile: public std::exception {
			public:
				const char *what() const throw();
		};
		class NegativeValue: public std::exception {
			public:
				const char *what() const throw();
		};
		class TooLargeValue: public std::exception {
			public:
				const char *what() const throw();
		};
		class TooEarlyDate: public std::exception {
			public:
				const char *what() const throw();
		};
		class CharInLine: public std::exception {
			public:
				const char *what() const throw();
		};
		class BadInput: public std::exception {
			private:
				std::string _errorMessage;
			public:
				BadInput( const std::string &message );
				const char *what() const throw();
				~BadInput() throw();
		};
		class InvalidDateFormat: public std::exception {
			private:
				std::string _errorMessage;
			public:
				InvalidDateFormat( const std::string &message );
				const char *what() const throw();
				~InvalidDateFormat() throw();
		};
	private :

		const char	*_fileName;
		std::ifstream	Data;
		std::map<std::string, float>	CsvMap;
		std::ifstream	txtfile;
};

bool containsOnlyDigits(const std::string& str);
