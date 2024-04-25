/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:37:13 by hrobin            #+#    #+#             */
/*   Updated: 2024/03/07 15:51:48 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
# include <iostream>
# include <string>
# include <exception>
# include <stdbool.h>

class Bureaucrat;

class AForm
{
	public :

		AForm();
		AForm(std::string name);
		AForm(std::string name, int GradeToApply, int GradeToExecute, bool state);
		virtual ~AForm();
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);

		std::string const get_name() const;
		bool get_state() const;
		int	get_grade_to_apply() const;
		int get_grade_to_exec() const;
		void beSigned(Bureaucrat* bob);
		void setStatus(bool status);
		void setGrades(int s, int e);
		virtual void execute (const Bureaucrat& executor) const = 0;

	class GradeTooHighException
	{
		public :
			virtual const char* what() const throw();
	};

	class GradeTooLowException
	{
		public :
			virtual const char* what() const throw();
	};

	class AlreadySignedException
	{
		public :
			virtual const char* what() const throw();
	};

	class NotSignedException
	{
		public :
			virtual const char* what() const throw();
	};

	private :

		std::string const _name;
		int Grade_to_apply;
		int Grade_to_execute;
		bool state;
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);
