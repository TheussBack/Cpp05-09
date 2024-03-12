/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:46:58 by hrobin            #+#    #+#             */
/*   Updated: 2024/03/12 19:51:15 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <iostream>
#include "Bureaucrat.hpp"

int main(void)
{
    std::cout << std::endl;
    std::cout << "⋇⊶⊰❣⊱⊷⋇" << std::endl;
    std::cout << std::endl;

    Bureaucrat francis("Francis", 20);
    std::cout << francis << std::endl;

    RobotomyRequestForm RobotForm("Denise");
    std::cout << RobotForm << std::endl;

    try {
        francis.signForm(RobotForm); // Sign the form
        if (RobotForm.get_state()) {
            francis.executeForm(RobotForm); // Execute the form
        } else {
            std::cout << "Error: The form was not successfully signed." << std::endl;
        }
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << RobotForm << std::endl;


    std::cout << std::endl;
    std::cout << "⋇⊶⊰❣⊱⊷⋇" << std::endl;
    std::cout << std::endl;

    PresidentialPardonForm PresidForm("Denise");
    std::cout << PresidForm << std::endl;

    try {
        francis.signForm(PresidForm);
        if (PresidForm.get_state()) {
            francis.executeForm(PresidForm);
        } else {
            std::cout << "Error: The form was not successfully signed." << std::endl;
        }
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << PresidForm << std::endl;


    std::cout << std::endl;
    std::cout << "⋇⊶⊰❣⊱⊷⋇" << std::endl;
    std::cout << std::endl;

    ShrubberyCreationForm ShrubForm("Denise");
    std::cout << ShrubForm << std::endl;

    try {
        francis.signForm(ShrubForm);
        if (ShrubForm.get_state()) {
            francis.executeForm(ShrubForm);
        } else {
            std::cout << "Error: The form was not successfully signed." << std::endl;
        }
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << ShrubForm << std::endl;


    std::cout << std::endl;
    std::cout << "⋇⊶⊰❣⊱⊷⋇" << std::endl;
    std::cout << std::endl;
}

