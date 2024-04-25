/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:44:00 by hrobin            #+#    #+#             */
/*   Updated: 2024/04/15 19:45:32 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//                      ── ⋅ ⋅ ── ✩Exceptions✩ ── ⋅ ⋅ ──

const char* BitcoinExchange::WrongArgNb::what() const throw()
{
    return "Wrong number of arguments.";
}

const char* BitcoinExchange::TooEarlyDate::what() const throw()
{
    return "no data for this date.";
}

const char* BitcoinExchange::InvalidFile::what() const throw()
{
    return "Error while opening the file.";
}

const char* BitcoinExchange::NegativeValue::what() const throw()
{
    return "not a positive number.";
}

const char* BitcoinExchange::TooLargeValue::what() const throw()
{
    return "too large a number.";
}

const char* BitcoinExchange::CharInLine::what() const throw()
{
    return "invalid character in line";
}

BitcoinExchange::BadInput::BadInput( const std::string & message ) {
    _errorMessage = BAD_INPUT_ERR + message;
}

BitcoinExchange::BadInput::~BadInput() throw() {}

const char *BitcoinExchange::BadInput::what() const throw() {
    return _errorMessage.c_str();
}

BitcoinExchange::InvalidDateFormat::InvalidDateFormat(const std::string & message) {
    _errorMessage = INVALID_DATE_ERR + message;
}

BitcoinExchange::InvalidDateFormat::~InvalidDateFormat() throw() {}

const char *BitcoinExchange::InvalidDateFormat::what() const throw() {
    return _errorMessage.c_str();
}

//                         ── ⋅ ⋅ ── ✩✩ ── ⋅ ⋅ ──

void BitcoinExchange::SetData() {

    std::ifstream file("data.csv");
    if (!file.is_open())
		throw BitcoinExchange::InvalidFile();
    file.close();
    Data.open("data.csv");
    StructureData();
}

void BitcoinExchange::StructureData() {

    std::string	sentence;

    while (std::getline(Data, sentence))
    {
	    processDataMapEntry(sentence);
    }
    Data.close();
}

static std::string LineCleaner(const std::string str) {

    std::string	newStr;

    for (size_t i = 0; i < str.size(); ++i) {
	if (!std::isspace(str[i])) {
	    newStr += str[i];
	}
    }
    return newStr;
}

static bool	ensureValidDate( const std::string & date ) {

    if (date.size() != 10)
        return false;

    if (date[4] != '-' || date[7] != '-')
        return false;

    int year, month, day;
    std::istringstream yearStream(date.substr(0, 4));
    std::istringstream monthStream(date.substr(5, 2));
    std::istringstream dayStream(date.substr(8, 2));

    if (!(yearStream >> year) || !(monthStream >> month) || !(dayStream >> day))
        return false;

    if (year < 1 || month < 1 || month > 12 || day < 1)
        return false;

    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            return day <= 29;
        } else {
            return day <= 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return day <= 30;
    }
    return true;
};

void BitcoinExchange::processDataMapEntry(const std::string line) {

    std::string trimmedLine = LineCleaner(line);
    std::size_t tokenPosition = trimmedLine.find(',');

    if (tokenPosition != std::string::npos) {
        std::string datePart = trimmedLine.substr(0, tokenPosition);
        std::string valuePart = trimmedLine.substr(tokenPosition + 1);

        std::istringstream valueStream(valuePart);
        float value;
        if (valueStream >> value) {
            if (ensureValidDate(datePart)) {
                CsvMap[datePart] = value;
                return;
            }
        }
    } else {
        throw InvalidFile();
    }
}

void BitcoinExchange::validateDateInput(const std::string &date) const {

    if (!ensureValidDate(date))
		throw BitcoinExchange::InvalidDateFormat(date);
}

void BitcoinExchange::SetFile(const char *filename) {

    std::ifstream file(filename);
    if (!file.is_open()) {
		throw BitcoinExchange::InvalidFile();
    }
    file.close();
    _fileName = filename;
    txtfile.open(filename);
}

void BitcoinExchange::processAndDisplay() {
    std::string line;
    while (std::getline(txtfile, line)) {
        try {
            processLine(line);
        } catch (const std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
}

void BitcoinExchange::processLine(const std::string& line) const {
    static bool firstLineSkipped = false;

    if (!firstLineSkipped) {
        firstLineSkipped = true;
        return;
    }

    std::string lineWithoutSpaces = LineCleaner(line);
    std::size_t separatorPos = lineWithoutSpaces.find_first_of(SEPARATORS);

    if (separatorPos != std::string::npos) {
        std::string datePart = lineWithoutSpaces.substr(0, separatorPos);
        std::string valuePart = lineWithoutSpaces.substr(separatorPos + 1);

        if (!containsOnlyDigits(valuePart)) {
            throw CharInLine();
        }

        std::istringstream valueStream(valuePart);
        float value;
        if (valueStream >> value) {
            validateDateInput(datePart);
            validateValue(value);
            std::string closestDate = findNearestDate(CsvMap, datePart);
            std::cout << datePart << " => " << value
                      << " = " << value * CsvMap.at(closestDate) << std::endl;
        }
    } else {
        throw BadInput(line);
    }
}

bool containsOnlyDigits(const std::string& str) {
    for (size_t i = 0; i < str.size(); ++i) {
        if (!isdigit(str[i]) && str[i] != '.' && str[i] != '-') {
            return false;
        }
    }
    return true;
}

void BitcoinExchange::validateValue(const float value) const {

    if (value < 0)
		throw NegativeValue();
    if (value > 100)
		throw TooLargeValue();
}

static std::string findNearestKey(const std::map<std::string, float>& myMap, const std::string& inputKey) {
    std::string closestKey = "";
    for (std::map<std::string, float>::const_iterator it = myMap.begin(); it != myMap.end(); ++it) {
		if (it->first <= inputKey)
	    	closestKey = it->first;
		else
	    	break;
    }
    return closestKey;
}

std::string BitcoinExchange::findNearestDate(const std::map<std::string, float>& myMap, const std::string& input) const {

    std::string closestDate = findNearestKey(myMap, input);

    if (closestDate.empty())
		throw TooEarlyDate();
    return closestDate;
}
