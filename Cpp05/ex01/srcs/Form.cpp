/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:08:01 by hrobin            #+#    #+#             */
/*   Updated: 2024/03/07 16:31:22 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


Form::Form() : _name("Taxes")
{
	Grade_to_apply = 150;
	Grade_to_execute = 150;
	state = 0;
	std::cout << "Form constructor's been called" << std::endl;
}

Form::Form(std::string name) : _name(name)
{
	std::cout << "Form constructor's been called" << std::endl;
}

Form::Form(const Form& other) : _name(other.get_name()), Grade_to_apply(other.get_grade_to_apply()), Grade_to_execute(other.get_grade_to_exec()), state(other.get_state())
{
}

Form::Form(std::string name, int GradeToApply, int GradeToExecute) : _name(name), Grade_to_apply(GradeToApply), Grade_to_execute(GradeToExecute)
{
	state = 0;
	
	try {
		setGrades(Grade_to_apply, Grade_to_execute);
	}
	catch(const Form::GradeTooHighException& e) {
		std::cerr << e.what() << '\n';
		return ;
	}
	catch(const Form::GradeTooLowException& e) {
		std::cerr << e.what() << '\n';
		return ;
	}

}

Form::~Form()
{
	std::cout << "Form destructor's been called" << std::endl;
}


Form& Form::operator=(const Form& other)
{
	(void)other;
	return (*this);
}

std::string const Form::get_name() const
{
	return _name;
}

void	Form::setGrades(int s, int e) {
	if (s > 150 || e > 150)
		throw GradeTooHighException();
	else if (s < 1 || e < 1)
		throw GradeTooLowException();
}

bool Form::get_state() const
{
	return state;
}

int	Form::get_grade_to_apply() const
{
	return Grade_to_apply;
}

int Form::get_grade_to_exec() const
{
	return Grade_to_execute;
}

const char*	Form::GradeTooLowException::what() const throw() {
	return "Grade needs to be higher.";
}

const char*	Form::GradeTooHighException::what() const throw() {
	return "Grade is too low.";
}

const char* Form::AlreadySignedException::what() const throw()
{
	return "The form is already signed.";
}

void Form::setStatus(bool status)
{
	state = status;
}

void Form::beSigned(Bureaucrat* bob)
{
    if (state == 1)
        throw Form::AlreadySignedException();
    if (bob->getGrade() <= Grade_to_apply) {
        setStatus(1);
        return;
    }
    throw Form::GradeTooLowException();
}



std::ostream& operator<<(std::ostream& os, const Form& obj)
{
	os << obj.get_name() << " is a form that requires a grade [" << obj.get_grade_to_apply() << "] [" << obj.get_grade_to_exec() << "] " << std::endl;
	if (obj.get_state() == 0)
		os << "This form is" << "\e[1m" << " NOT " << "\e[0m" << "signed" << std::endl;
	else
		os << "This form as been" << "\e[1m" << " SIGNED " << "\e[0m" << std::endl;
	return os;
}
