/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:44:08 by hrobin            #+#    #+#             */
/*   Updated: 2024/04/15 17:18:40 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


int	main(int ac, char **av)
{
	try {
		BitcoinExchange bitcoin( ac, av[1] );
		bitcoin.processAndDisplay();
	}
	catch (std::exception &e) {
		std::cout << "Error : " << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
