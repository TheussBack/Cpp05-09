/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:08:01 by hrobin            #+#    #+#             */
/*   Updated: 2024/03/08 13:47:05 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"


AForm::AForm() : _name("Taxes")
{
	Grade_to_apply = 150;
	Grade_to_execute = 150;
	state = 0;
	std::cout << "AForm constructor's been called" << std::endl;
}

AForm::AForm(std::string name) : _name(name)
{
	std::cout << "AForm constructor's been called" << std::endl;
}

AForm::AForm(const AForm& other) : _name(other.get_name()), Grade_to_apply(other.get_grade_to_apply()), Grade_to_execute(other.get_grade_to_exec()), state(other.get_state()) {}

AForm::AForm(std::string name, int GradeToApply, int GradeToExecute, bool _state) : _name(name), Grade_to_apply(GradeToApply), Grade_to_execute(GradeToExecute), state(_state)
{
	try {
		setGrades(Grade_to_apply, Grade_to_execute);
	}
	catch(const AForm::GradeTooHighException& e) {
		std::cerr << e.what() << '\n';
		return ;
	}
	catch(const AForm::GradeTooLowException& e) {
		std::cerr << e.what() << '\n';
		return ;
	}

}

AForm::~AForm()
{
	std::cout << "AForm destructor's been called" << std::endl;
}


AForm& AForm::operator=(const AForm& other)
{
	(void)other;
	return (*this);
}

std::string const AForm::get_name() const
{
	return _name;
}

void	AForm::setGrades(int s, int e) {
	if (s > 150 || e > 150)
		throw GradeTooHighException();
	else if (s < 1 || e < 1)
		throw GradeTooLowException();
}

bool AForm::get_state() const
{
	return state;
}

int	AForm::get_grade_to_apply() const
{
	return Grade_to_apply;
}

int AForm::get_grade_to_exec() const
{
	return Grade_to_execute;
}

const char*	AForm::GradeTooLowException::what() const throw() {
	return "Grade needs to be higher.";
}

const char*	AForm::GradeTooHighException::what() const throw() {
	return "Grade is too low.";
}

const char* AForm::AlreadySignedException::what() const throw()
{
	return "The Form is already signed.";
}

const char* AForm::NotSignedException::what() const throw()
{
	return "The form is not signed yet";
}

void AForm::setStatus(bool status)
{
	state = status;
}

void AForm::beSigned(Bureaucrat* bob)
{
    if (state == 1)
        throw AForm::AlreadySignedException();
    if (bob->getGrade() <= Grade_to_apply) {
        setStatus(1);
        return;
    }
    throw AForm::GradeTooLowException();
}



std::ostream& operator<<(std::ostream& os, const AForm& obj)
{
	os << obj.get_name() << " is a AForm that requires a grade [" << obj.get_grade_to_apply() << "] [" << obj.get_grade_to_exec() << "] " << std::endl;
	if (obj.get_state() == 0)
		os << "This AForm is" << "\e[1m" << " NOT " << "\e[0m" << "signed" << std::endl;
	else
		os << "This AForm as been" << "\e[1m" << " SIGNED " << "\e[0m" << std::endl;
	return os;
}
