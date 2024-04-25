/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:37:32 by hrobin            #+#    #+#             */
/*   Updated: 2024/04/05 16:19:03 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(const Span& other)
	{
		if ( this != &other )
		{
        numbers = other.numbers;
        max_size = other.max_size;
    	}
	}
Span& Span::operator=(const Span &other)
	{
		if ( this != &other ) {
        if ( max_size != other.max_size )
            throw std::length_error( "different size spans" );
        numbers = other.numbers;
        // max_size = other.max_size;
    }
    return (*this);
	}

void Span::addNumber(int number) {
        if (numbers.size() >= max_size) {
			throw Span::tooManyStoredIntegers();
        }
        numbers.push_back(number);
    }

int Span::shortestSpan() {
        if (numbers.size() <= 1) {
			throw tooFewStoredIntegers();
        }
        std::sort(numbers.begin(), numbers.end());
        int shortest_distance = std::numeric_limits<int>::max();
        for (size_t i = 1; i < numbers.size(); ++i) {
            int distance = numbers[i] - numbers[i - 1];
            if (distance < shortest_distance) {
                shortest_distance = distance;
            }
        }
        return shortest_distance;
    }

int Span::longestSpan() {
        if (numbers.size() <= 1) {
			throw tooFewStoredIntegers();
        }
        std::sort(numbers.begin(), numbers.end());
        return numbers.back() - numbers.front();
    }
