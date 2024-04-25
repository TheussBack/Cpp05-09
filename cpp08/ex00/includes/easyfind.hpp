/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:19:37 by hrobin            #+#    #+#             */
/*   Updated: 2024/04/05 15:34:57 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <list>

template<typename T>
typename T::iterator easyfind(T& t, int value)
{
	if (std::find(t.begin(), t.end(), value) == t.end())
		throw std::length_error("the list does not contain your object");
	return (std::find(t.begin(), t.end(), value));
}
