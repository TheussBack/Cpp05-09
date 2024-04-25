/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:15:15 by hrobin            #+#    #+#             */
/*   Updated: 2024/03/28 15:15:17 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

static void Print(const Data *Data_instance) {
    std::cout << "int : " << Data_instance->_int << std::endl;
    std::cout << "char : " << Data_instance->_char << std::endl;
    std::cout << "size_t : " << Data_instance->_size_t << std::endl;
    std::cout << "string : " << Data_instance->_string << std::endl;
    std::cout << "void : " << Data_instance->_void << std::endl;
}

int main( void ) {
    Data    *randomDataSet = new Data;
    Data    *RandomSetAgain = NULL;

    randomDataSet->_int = -12;
    randomDataSet->_char = 'x';
    randomDataSet->_size_t = 41;
    randomDataSet->_void = NULL;
    randomDataSet->_string = "je suis un tset";

    std::cout << "\033[0;32m";
    Print(randomDataSet);
    RandomSetAgain = Serializer::deserialize(Serializer::serialize(randomDataSet));
    std::cout << "\033[0;31m";
    Print(RandomSetAgain);
    std::cout << "\033[0m";
    delete RandomSetAgain;
}
