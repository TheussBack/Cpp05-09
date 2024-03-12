/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:47:11 by hrobin            #+#    #+#             */
/*   Updated: 2024/03/12 19:21:56 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

void	Bureaucrat::setGrade( int grade ) {
    if (grade > 150)
        throw Bureaucrat::GradeTooHighException();
    else if (grade < 1)
        throw Bureaucrat::GradeTooLowException();
    else
        _grade = grade;
}

std::string const	Bureaucrat::getName() const {
	return _name;
}

int 				Bureaucrat::getGrade() const {
	return _grade;
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low.";
}

const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high.";
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat &old ) {
	std::cout << "Bureaucrat Assignment operator called for Bureaucrat." << std::endl;
	if (this != &old) {
		_grade = old.getGrade();
	}
	return *this;
}

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {
	try {
		this->setGrade(150);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "Bureaucrat Default Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat( int grade ) : _name("default") {
	try {
		this->setGrade(grade);
	} catch (std::exception &e)  {
		std::cerr << e.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name) {
	try {
		this->setGrade(grade);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "Bureaucrat Constructor called for " << _name << '.' << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat &old ) : _name(old.getName() + "_new") {
	std::cout << "Bureaucrat Copy Constructor called." << std::endl;
	(*this) = old;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat Default Destructor called for " << _name << '.' << std::endl;
}

void			Bureaucrat::incrementGrade() {
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void			Bureaucrat::decrementGrade() {
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

std::ostream	&operator<<( std::ostream &o, const Bureaucrat &curr ) {
	o << curr.getName() << ", bureaucrat grade " << curr.getGrade() << '.' << std::endl;
	return o;
}
