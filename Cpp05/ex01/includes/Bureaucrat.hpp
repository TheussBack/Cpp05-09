/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:47:19 by hrobin            #+#    #+#             */
/*   Updated: 2024/03/06 21:16:50 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include <exception>
# include "Form.hpp"

class Form;

class Bureaucrat
{
public:

	Bureaucrat();
	Bureaucrat( int grade );
	Bureaucrat( std::string name, int grade );
	Bureaucrat( const Bureaucrat &old );
	~Bureaucrat();

	Bureaucrat&	operator=( const Bureaucrat &old );

	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

	std::string const	getName() const;
	int					getGrade() const;

	void				setGrade( int grade );

	void				incrementGrade();
	void				decrementGrade();
	void				signForm( Form& );

private:

	std::string const	_name;
	int					_grade;

};

//the problem was me doing : std::cout << *bureaucrat_name instead of : std::cout << bureaucrat_name since I use a reference and not a pointer

std::ostream	&operator<<( std::ostream &o, const Bureaucrat &curr );
