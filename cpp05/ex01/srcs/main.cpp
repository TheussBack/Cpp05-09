/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:46:58 by hrobin            #+#    #+#             */
/*   Updated: 2024/03/07 17:01:29 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << std::endl;
	std::cout << "⋇⊶⊰❣⊱⊷⋇" << std::endl;
	std::cout << std::endl;

	Bureaucrat francis("Francis", 100);
	std::cout << francis << std::endl;

	Form form1("Taxes", 100, 100);
	std::cout << "A new form is available !" << std::endl;
	form1.beSigned(&francis);
	std::cout << form1 << std::endl;

	std::cout << "⋇⊶⊰❣⊱⊷⋇" << std::endl;
	std::cout << std::endl;

	Form form2("NDA", 1, 100);
	std::cout << "A new form is available !" << std::endl;
	francis.signForm(form2);
	std::cout << form2 << std::endl;

	std::cout << "⋇⊶⊰❣⊱⊷⋇" << std::endl;
	std::cout << std::endl;

	Form form3("Other Paper", 10, 50);
	std::cout << "A new form is available !" << std::endl;
	francis.signForm(form3);
	std::cout << form3 << std::endl;

	std::cout << "⋇⊶⊰❣⊱⊷⋇" << std::endl;
	std::cout << std::endl;

	std::cout << "\033[3;104;30mNow adding another Bureaucrat !\033[0m" << std::endl;
	std::cout << std::endl;

	Bureaucrat Daniel("Daniel", 1);
	std::cout << Daniel << std::endl;

	std::cout << "₊˚ପ⊹ He's a real genius he must be able to sign everything !₊˚ପ⊹" << std::endl;
	std::cout << std::endl;

	Form form4("Nasa files", 10, 10);
	std::cout << "A new form is available !" << std::endl;
	form4.beSigned(&Daniel);
	std::cout << form4 << std::endl;

	std::cout << std::endl;
	std::cout << "What if the form needs a too high grade" << std::endl;
	std::cout << std::endl;

	Form form5("Corrupted one", 1000000, 10990);
	std::cout << form5 << std::endl;

	Form form6("Corrupted one", 0, 0);
	std::cout << form6 << std::endl;


	return (0);
}
