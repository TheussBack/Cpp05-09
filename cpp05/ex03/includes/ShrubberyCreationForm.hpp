/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:10:07 by hrobin            #+#    #+#             */
/*   Updated: 2024/03/25 18:10:09 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"

class ShrubberyCreationForm : public Form {
	private:
		const std::string	_target;

		ShrubberyCreationForm();
	public:
		ShrubberyCreationForm( std::string target );
		ShrubberyCreationForm( const ShrubberyCreationForm &old );
		~ShrubberyCreationForm();

		ShrubberyCreationForm	&operator=( const ShrubberyCreationForm &old );

		void		execute( Bureaucrat const & executor ) const;
};
