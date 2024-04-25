/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:09:43 by hrobin            #+#    #+#             */
/*   Updated: 2024/03/25 18:09:45 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"

class PresidentialPardonForm : public Form {
	private:
		const std::string	_target;

		PresidentialPardonForm();
	public:
		PresidentialPardonForm( std::string target );
		PresidentialPardonForm( const PresidentialPardonForm &old );
		~PresidentialPardonForm();

		PresidentialPardonForm&	operator=( const PresidentialPardonForm &old );

		void	execute( const Bureaucrat & executor ) const;
};
