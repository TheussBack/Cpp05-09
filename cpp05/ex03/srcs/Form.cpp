/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:10:26 by hrobin            #+#    #+#             */
/*   Updated: 2024/03/25 18:10:28 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

void	Form::setStatus( bool status ) {
	_isSigned = status;
}

const char	*Form::notSignedException::what() const throw() {
	return	"The Form isn't signed yet";
}

const char	*Form::alreadySignedException::what() const throw() {
	return	"The Form is already signed";
}

const char	*Form::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

const char	*Form::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

void	Form::beSigned( const Bureaucrat &Signatory ) {
	if ( _isSigned == 1 )
		throw	Form::alreadySignedException();
	if ( Signatory.getGrade() <= getSignReq() )
		return	setStatus(1);
	throw	Form::GradeTooLowException();
}

Form::Form() : _Name("default_form"), _signReq(150), _execReq(150), _isSigned(0) {
	return;
}

Form::Form( std::string Name, int signReq, int execReq, bool isSigned ) : _Name(Name), _signReq(signReq), _execReq(execReq), _isSigned(isSigned) {
    if (_signReq > 150 || _execReq > 150)
        throw Form::GradeTooLowException();
    else if (_signReq < 1 || _execReq < 1)
        throw Form::GradeTooHighException();
}

Form::Form( const Form &old ) : _Name( old.getName()), _signReq(old.getSignReq()), _execReq(old.getExecReq()), _isSigned(old.getStatus()) {}

Form::~Form() {
	return;
}

std::string	const Form::getName() const {
	return	_Name;
}

int	Form::getSignReq() const {
	return	_signReq;
}

int	Form::getExecReq() const {
	return	_execReq;
}

bool	Form::getStatus() const {
	return	_isSigned;
}

std::ostream&	operator<<( std::ostream& o, const Form& curr ) {
	o << curr.getName() << "'s required signing and executing grades are : ["
		<< curr.getSignReq() << "," << curr.getExecReq() << "]. ";
	if ( curr.getStatus() == 1 )
		o << "The Form is signed." << std::endl;
	else
		o << "The Form isn't signed" << std::endl;
	return	o;
}
