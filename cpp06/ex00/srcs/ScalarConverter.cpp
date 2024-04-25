/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:31:57 by hrobin            #+#    #+#             */
/*   Updated: 2024/03/27 14:37:45 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

std::string	ScalarConverter::NoMantissaFloat( float f ) { // cheque si il y a une mantisse (partie decimale)
	std::cout << f;
	if (!(std::abs(f - trunc(f)) < 1e-5) && !(std::abs(f - trunc(f)) < 1e-4))
		return	"f";
	return	".0f";
}

std::string	ScalarConverter::isPrintableChar( char c ) {
	if (c >= 33 && c <= 126) {
		std::cout << c;
		return	"";
	}
	return	"n/a";
}

std::string	ScalarConverter::NoMantissaDouble( double d ) {
	std::cout << d;
	if (!(std::abs(d - trunc(d)) < 1e-5) && !(std::abs(d - trunc(d)) < 1e-4))
		return	"";
	return	".0";
}


void    ScalarConverter::convertFromInt( int x ) {
	std::cout << "\033[0;36mchar : " << isPrintableChar(static_cast<char>(x)) << std::endl;
	std::cout << "\033[0;38mint : " << x << std::endl; // lui meme
	std::cout << "\033[0;31mfloat : " << NoMantissaFloat(static_cast<float>(x)) << std::endl;
	std::cout << "\033[1;33mdouble : " << NoMantissaDouble(static_cast<double>(x)) << std::endl;
	std::cout << "\033[0m";
}

void    ScalarConverter::convertFromChar( char c ) {
	std::cout << "\033[0;36mchar : " << c << std::endl;
	std::cout << "\033[0;38mint : " << static_cast<int>(c) << std::endl;
	std::cout << "\033[0;31mfloat : " << NoMantissaFloat(static_cast<float>(c)) << std::endl;
	std::cout << "\033[1;33mdouble : " << NoMantissaDouble(static_cast<double>(c)) << std::endl;
	std::cout << "\033[0m";
}

void    ScalarConverter::convertFromFloat( float f ) {

	std::cout << "\033[0;36mchar : " << isPrintableChar(static_cast<char>(f)) << std::endl;
	std::cout << "\033[0;38mint : " << static_cast<int>(f) << std::endl;
	std::cout << "\033[0;31mfloat : " << NoMantissaFloat(f) << std::endl;
	std::cout << "\033[1;33mdouble : " << NoMantissaDouble(static_cast<double>(f)) << std::endl;
	std::cout << "\033[0m";
}

void    ScalarConverter::convertFromDouble( double d ) { //Le double sans mantisse ou avec une mantisse selon le cas
	std::cout << "\033[0;36mchar : " << isPrintableChar(static_cast<char>(d)) << std::endl;
	std::cout << "\033[0;38mint : " << static_cast<int>(d) << std::endl;
	std::cout << "\033[0;31mfloat : " << NoMantissaFloat(static_cast<float>(d)) << std::endl;
	std::cout << "\033[1;33mdouble : " << NoMantissaDouble(d) << std::endl;
	std::cout << "\033[0m";
}

bool is_it_Char( const std::string &input ) { //verifie si une chaine de char correspondent a un char un int un double ou un float
	return input.length() == 1;
}

bool is_it_Int( const std::string &input ) {
	if (input.empty()) return false;
	char* end;
	strtol(input.c_str(), &end, 10);
	return (*end == '\0');
}

bool is_it_Double( const std::string &input ) {
	if ( input.empty() || input.find(".") == std::string::npos || input.find(".") + 1 == input.length()) return false;
	char* end;
	strtod(input.c_str(), &end);
	return (*end == '\0');
}

bool is_it_Float(const std::string& input) {
	if ( input.empty() || input.find(".") == std::string::npos || input.find("f") - 1 == input.find(".")) return false;
	char* end;
	strtof(input.c_str(), &end); // transforme chaîne de caractères en un nombre à virgule flottante
	return (*end == 'f' && errno != ERANGE);
}

void    ScalarConverter::transposer( const std::string &input ) { //décide du type de conversion à effectuer en fonction de la valeur de la chaîne.
	char*   end;

	if (input == "nan" || input == "nanf" || input == "+inf" || input == "-inf"
			|| input == "+inff" || input == "-inff")
		{
			std::cout << "\033[0;36mchar : impossible" << std::endl;
			if (input == "nan" || input == "nanf") {
				std::cout << "\033[0;38mint : impossible" << std::endl;
				std::cout << "\033[0;31mfloat : nanf" << std::endl;
				std::cout << "\033[1;33mdouble : nan" << std::endl;
				std::cout << "\033[0m";
			}
			if (input == "+inf" || input == "-inf") {
				std::cout << "\033[0;38mint : impossible" << std::endl;
				std::cout << "\033[0;31mfloat : +inff" << std::endl;
				std::cout << "\033[1;33mdouble : " << input << std::endl;
				std::cout << "\033[0m";
			}
			if (input == "+inff" || input == "-inff")
			{
				std::cout << "\033[0;38mint : impossible" << std::endl;
				std::cout << "\033[0;31mfloat : " << input << std::endl;
				std::cout << "\033[1;33mdouble : " << input << std::endl;
				std::cout << "\033[0m";
			}
			return	;
		}
	if (is_it_Float(input)) {
		convertFromFloat(strtof(input.c_str(), &end));
	} else if (is_it_Double(input)) {
		convertFromDouble(strtod(input.c_str(), &end));
	} else if (is_it_Int(input)) {
		convertFromInt(strtol(input.c_str(), &end, 10));
	} else if (is_it_Char(input)) {
		convertFromChar(input[0]);
	} else {
		std::cout << "\033[1;31minput is not valid\033[0m" << std::endl;
	}
}
