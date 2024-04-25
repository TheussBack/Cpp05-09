/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:35:47 by hrobin            #+#    #+#             */
/*   Updated: 2024/04/05 16:19:11 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "Span.cpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
Span sp = Span(100);
// sp.addNumber(6);
// sp.addNumber(3);
// sp.addNumber(17);
// sp.addNumber(9);
// sp.addNumber(11);
srand(time(NULL));
try{
	for (int i = 0; i < 100; i++) {
            int random_number = rand() % 100;
            sp.addNumber(random_number);
            std::cout << "Nombre aléatoire ajouté : " << random_number << std::endl;
	}
}
catch (std::exception& e){
        std::cout << "Error: " << e.what() << std::endl;
}

try
{
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}
catch(const std::exception& e)
{
	std::cerr << e.what() << '\n';
}

return 0;
}

// int main() {
//     Span span(10000);
//     for (int i = 1; i <= 10000; ++i) {
//         span.addNumber(i);
//     }

//     std::cout << "Plus petite distance : " << span.shortestSpan() << std::endl;
//     std::cout << "Plus grande distance : " << span.longestSpan() << std::endl;

//     return 0;
// }
