/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:47:55 by hrobin            #+#    #+#             */
/*   Updated: 2024/03/12 19:23:39 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string targetparam) : AForm("RobotomyRequestForm", 72, 45, 0), target(targetparam)
{
	std::cout << "RobotForm constructor called" << std::endl;
}
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotForm destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
{
	(void)other;
	std::cout << "Recopy called" << std::endl;
}

std::string RobotomyRequestForm::get_target()
{
	return target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	(void)other;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (get_state() == 0)
		throw NotSignedException();
	if (executor.getGrade() > get_grade_to_exec()) // Vérification si le grade de l'exécutant est inférieur ou égal au grade requis
		throw GradeTooLowException();
	else
	{
		static int i = 0;
		if (i % 2 == 0)
			std::cout << "DrrrRRrrzzZzz.... " << target << " has been robotomized !" << std::endl;
		else
			std::cout << "Robotomization failed ! " << target << " is safe :)" << std::endl;
		i++;
	}
}
