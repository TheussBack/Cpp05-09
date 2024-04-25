/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:17:57 by uniix             #+#    #+#             */
/*   Updated: 2024/03/25 12:31:16 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t	Serializer::serialize( Data *ptr ) {
	return	reinterpret_cast<uintptr_t>(ptr);
}

Data		*Serializer::deserialize( uintptr_t raw ) {
	return	reinterpret_cast<Data *>(raw);
}
