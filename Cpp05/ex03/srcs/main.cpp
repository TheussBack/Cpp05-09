/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:10:36 by hrobin            #+#    #+#             */
/*   Updated: 2024/03/25 18:26:22 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
		std::cout << std::endl;

		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		std::cout << std::endl;
		Bureaucrat *a = new Bureaucrat("Fabien", 1);
		std::cout << std::endl;
		Intern *z = new Intern();
		Form *b = z->makeForm("RobotomyRequestForm", "Bender");
		Form *c = z->makeForm("ShrubberyCreationForm", "Denise");
		std::cout << std::endl;

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << std::endl;
		std::cout << *a;
		std::cout << std::endl;
		std::cout << *b;
		std::cout << *c;
		std::cout << std::endl;

		b->beSigned(*a);
		a->signForm(*c);
		std::cout << std::endl;
		std::cout << *b;
		std::cout << *c;
		std::cout << std::endl;

		for (int i= 0; i < 10; i++)
			b->execute(*a);
		a->executeForm(*c);
		
		std::cout << std::endl;

		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		delete a;
		delete b;
		delete c;
		delete z;
		std::cout << std::endl;
	return (0);
}
