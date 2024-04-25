/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:47:19 by hrobin            #+#    #+#             */
/*   Updated: 2024/04/01 17:54:44 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include <exception>

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

private:

	std::string const	_name;
	int					_grade;

};

std::ostream	&operator<<( std::ostream &o, const Bureaucrat &curr );
