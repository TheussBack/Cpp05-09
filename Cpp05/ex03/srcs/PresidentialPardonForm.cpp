/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:21:35 by maparigi          #+#    #+#             */
/*   Updated: 2023/07/11 17:28:36 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : Form("PresidentialPardonForm", 25, 5, 0), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &old ) : Form(old), _target(old._target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm&	PresidentialPardonForm::operator=( const PresidentialPardonForm &old ) {
	(void)old;
	return *this;
}

void	PresidentialPardonForm::execute( const Bureaucrat & executor ) const {
	if ( getStatus() == 0 )
		throw	notSignedException();
	if ( executor.getGrade() > getExecReq() )
		throw	GradeTooLowException();
	else
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}