/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:10:12 by hrobin            #+#    #+#             */
/*   Updated: 2024/03/25 18:10:14 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"

class RobotomyRequestForm : public Form {
	private:
		const std::string	_target;

		RobotomyRequestForm();
	public:
		RobotomyRequestForm( std::string target );
		RobotomyRequestForm( const RobotomyRequestForm &old );
		~RobotomyRequestForm();

		RobotomyRequestForm&	operator=( const RobotomyRequestForm &old );

		void	execute( Bureaucrat const & executor ) const;
};
