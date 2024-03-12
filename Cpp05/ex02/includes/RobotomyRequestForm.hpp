/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:09:30 by hrobin            #+#    #+#             */
/*   Updated: 2024/03/12 18:08:04 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "AForm.hpp"
class Form;

class RobotomyRequestForm : public AForm
{
	public :
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

		void execute(Bureaucrat const & executor) const;
		std::string get_target();

	private :

		const std::string target;
};
