/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:18:24 by maparigi          #+#    #+#             */
/*   Updated: 2024/03/25 18:19:49 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : Form("ShrubberyCreationForm", 145, 137, 0), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &old ) : Form(old), _target(old._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm &old ) {
    (void)old;
    return	*this;
}

void	ShrubberyCreationForm::execute( Bureaucrat const & executor ) const {
    if ( getStatus() == 0 )
		throw	notSignedException();
    if ( executor.getGrade() > getExecReq() )
		throw	GradeTooLowException();
    std::string		fname = _target + "_shrubbery";
    std::ofstream	Shrubfile( fname.c_str() );
    if (Shrubfile.is_open()) {
		Shrubfile << "          &&& &&  & &&" << std::endl;
      	Shrubfile << "      && &\\/&\\|& ()|/ @, &&" << std::endl;
     	Shrubfile << "      &\\/(/&/&||/& /_/)_&/_&" << std::endl;
   		Shrubfile << "   &() &/&|()|/&/ '% & &" << std::endl;
  		Shrubfile << "  &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl;
		Shrubfile << "&&   && & &| &| /& & % ()& /&&" << std::endl;
 		Shrubfile << " ()&_---()\\&\\|&&-&&--%---()~" << std::endl;
     	Shrubfile << "     &&    \\|||" << std::endl;
        Shrubfile << "             |||" << std::endl;
        Shrubfile << "             |||" << std::endl;
        Shrubfile << "             |||" << std::endl;
       	Shrubfile << "       , -=-~  .-^- _" << std::endl;
		Shrubfile.close();
    }
}
