/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:28:53 by hrobin            #+#    #+#             */
/*   Updated: 2024/04/05 16:19:20 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

class Span {
private:
    size_t max_size;
    std::vector<int> numbers;

public:
    Span(unsigned int N) : max_size(N) {}
	~Span(){}
	Span(const Span& other);
	Span& operator=(const Span &other);

    void addNumber(int number) ;

    int shortestSpan();

    int longestSpan();

	class tooManyStoredIntegers : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return  ("La capacité maximale de la Span est atteinte");
                };
	};
	class tooFewStoredIntegers : public std::exception {
            public:
                virtual const char * what() const throw() {
                    return  ("Pas assez de nombres pour calculer la distance");
                }
	};
};
