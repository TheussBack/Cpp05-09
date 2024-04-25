/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:41:13 by hrobin            #+#    #+#             */
/*   Updated: 2024/03/12 19:01:33 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string targetparam) : AForm("ShrubberyCreationForm", 145, 137, 0), target(targetparam)
{
	std::cout << "Constuctor has been called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Destructor has been called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.target)
{
	std::cout << "Recopy called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	(void)other;
	return (*this);
}


void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (get_state() == 0)
        throw NotSignedException();
    if (executor.getGrade() > get_grade_to_exec())
        throw GradeTooLowException();
    std::string fname = target + "_shrubbery";
    std::cout << "Creating file with name: " << fname << std::endl; // Print filename
    std::ofstream fichier(fname.c_str());
    if (fichier.is_open())
    {
		fichier << "          &&& &&  & &&" << std::endl;
      	fichier << "      && &\\/&\\|& ()|/ @, &&" << std::endl;
     	fichier << "      &\\/(/&/&||/& /_/)_&/_&" << std::endl;
   		fichier << "   &() &/&|()|/&/ '% & &" << std::endl;
  		fichier << "  &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl;
		fichier << "&&   && & &| &| /& & % ()& /&&" << std::endl;
 		fichier << " ()&_---()\\&\\|&&-&&--%---()~" << std::endl;
     	fichier << "     &&    \\|||" << std::endl;
        fichier << "             |||" << std::endl;
        fichier << "             |||" << std::endl;
        fichier << "             |||" << std::endl;
       	fichier << "       , -=-~  .-^- _" << std::endl;
		fichier.close();
	}
}
