/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:11:33 by hrobin            #+#    #+#             */
/*   Updated: 2024/03/29 15:00:23 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
template< typename T >

class Array
{
	private:
		T 				*_array;
		unsigned int	_size;
	public:
		Array() : _array(NULL), _size( 0 ) {};
		Array( unsigned int n ) : _array( new T[n] ), _size( n ) {
			for ( unsigned int i = 0; i < n; i++ )
				_array[i] = 0;
		};
		Array( const Array &old ) : _array(NULL) {
			*this = old;
		};
		~Array() {
			delete []	_array;
		};

		Array & operator=( const Array & old ) {
			if ( this != &old ) {
				delete []	_array;
				_size = old._size;
				_array = new T[_size];
				for ( size_t i = 0; i < _size; i++ )
					_array[i] = *old._array;
			}
			return	*this;
		};
		class	IndexTooLow : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("Index is too low");
				};
		};
		class	IndexTooHigh : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("Index is too high");
				};
		};
		class	EmptyArray : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("Array is empty");
				};
		};
		T &	operator[]( int index ) { //permet de faire acceder au elements de array comme un tab
			if (static_cast< int >(_size) == 0)
				throw	Array::EmptyArray();
			if (index < 0)
				throw	Array::IndexTooLow();
			if (index >= static_cast< int >(_size))
				throw	Array::IndexTooHigh();
			return _array[index];
		}
		unsigned int size() const {
        return _size;
		}
} ;
