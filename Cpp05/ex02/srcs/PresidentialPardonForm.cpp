/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:30:25 by hrobin            #+#    #+#             */
/*   Updated: 2024/03/12 18:15:50 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string targetparam) : AForm("PresidentialPardonForm", 25, 5, 0), target(targetparam)
{
	std::cout << "PrsidentForm constructor called" << std::endl;
}
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PrsidentForm destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
{
	(void)other;
	std::cout << "Recopy called" << std::endl;
}

std::string PresidentialPardonForm::get_target()
{
	return target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	(void)other;
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (get_state() == 0)
		throw NotSignedException();
	if (executor.getGrade() > get_grade_to_exec())
		throw GradeTooLowException();
	else
	{
			std::cout << "Hey ! " << target << " has been pardoned by Zaphod Beeblebrox :)" << std::endl;
	}
}
