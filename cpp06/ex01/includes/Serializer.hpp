/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:12:41 by uniix             #+#    #+#             */
/*   Updated: 2024/03/27 14:44:58 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include <stdint.h>

struct	Data {
	size_t		_size_t;
	int			_int;
	std::string	_string;
	void		*_void;
	char		_char;
};

class Serializer {
	private:
		Serializer();
		Serializer( const Serializer &other );
		~Serializer();

		Serializer &operator=( const Serializer &other );
	public:
		static uintptr_t	serialize( Data *ptr );

		static Data*		deserialize( uintptr_t raw );
};
