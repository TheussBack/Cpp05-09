/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:04:04 by uniix             #+#    #+#             */
/*   Updated: 2024/03/27 14:37:45 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <cmath>
# include <string>
# include <cerrno>
# include <cstdlib>
# include <sstream>
# include <iostream>

class ScalarConverter
{
	private :
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter( const ScalarConverter &other );
		ScalarConverter	&	operator=( const ScalarConverter &other );
		double doubleType;
		float floatType;
		char charType;
		int intType;

	public :
		static void	transposer( const std::string &input );
		static void convertFromInt( int x );
		static void convertFromChar( char c );
		static void convertFromFloat( float f );
		static void convertFromDouble( double d );

		static std::string	isPrintableChar( char c );

		static std::string	NoMantissaFloat( float f );
		static std::string	NoMantissaDouble( double d );
};
