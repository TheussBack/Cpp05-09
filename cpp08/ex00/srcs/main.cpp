/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:19:20 by hrobin            #+#    #+#             */
/*   Updated: 2024/04/05 15:34:52 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include "easyfind.hpp"

int main() {
    std::vector<int> vec;

    for (int i = 1; i <= 5; i++)
    {
        vec.push_back(i);
    }

    std::list<int> lst;

    for (int i = 6; i <= 10; i++)
    {
        lst.push_back(i);
    }


    try {
        std::vector<int>::iterator it1 = easyfind(vec, 3);
        std::cout << "Valeur trouvée à la position (vector) : " << std::distance(vec.begin(), it1) << std::endl;

        std::list<int>::iterator it2 = easyfind(lst, 6);
        std::cout << "Valeur trouvée à la position (list) : " << std::distance(lst.begin(), it2) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    return 0;
}
