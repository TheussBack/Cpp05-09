/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparigi <maparigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:12:31 by maparigi          #+#    #+#             */
/*   Updated: 2023/07/11 16:55:38 by maparigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : Form("RobotomyRequestForm", 72, 45, 0), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &old ) : Form(old), _target(old._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm&	RobotomyRequestForm::operator=( const RobotomyRequestForm &old ) {
	(void)old;
	return *this;
}

void	RobotomyRequestForm::execute( Bureaucrat const & executor ) const {
    if ( getStatus() == 0 )
		throw	notSignedException();
    if ( executor.getGrade() > getExecReq() )
		throw	GradeTooLowException();
	else {
		static int	i;
		if ( i % 2 == 0 )
			std::cout << "BZZZZZT! " << _target << " has been robotomized!" << std::endl;
        else
			std::cout << "Robotomy failed! " << _target << " is still alive." << std::endl;
		i++;
    }
}