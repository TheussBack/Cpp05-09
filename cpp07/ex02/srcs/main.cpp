/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:10:11 by hrobin            #+#    #+#             */
/*   Updated: 2024/03/29 15:14:44 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#include <string>
#include <iostream>

int main() {
    Array<int> numbers(12);
    Array<char> charArray(11);
    Array<double> chardoub(69);
    Array<int> idk;
	char *	a = new char();

	std::cout << "Printing allocated char : " << std::endl;
	std::cout << *a << std::endl;
	std::cout << std::endl;

    std::cout << "Numbers array:" << std::endl;
    for (int i = 0; i < 12; ++i) {
        std::cout << numbers[i] << " ";
    }

	std::cout << std::endl;
	std::cout << "Size of the array: " << numbers.size() << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < 11; ++i) {
        charArray[i] = 'A' + i;
    }

    std::cout << "Characters array:" << std::endl;
    for (int i = 0; i < 11; ++i) {
        std::cout << charArray[i] << " ";
    }
    std::cout << std::endl;
	std::cout << "Size of the array: " << charArray.size() << std::endl;
    std::cout << std::endl;

    try {
        std::cout << numbers[1223] << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error : " << e.what() << std::endl;
    }
    try {
        std::cout << idk[0] << std::endl;
    } catch (std::exception &e) {
        std::cout << "FATAL ERROR : " << e.what() << std::endl;
    }

    for (int i = 0; i < 69; i++) {
        chardoub[i] = static_cast< double >(i);
    }
    for (int i = 0; i < 70; i++) {
        try {
                std::cout << chardoub[i] << " ";
        } catch (std::exception &e) {
			std::cout << std::endl;
            std::cout << "FATAL ERROR : " << e.what() << std::endl;
        }
    }

    std::cout << std::endl;

    delete a;

    return 0;
}
