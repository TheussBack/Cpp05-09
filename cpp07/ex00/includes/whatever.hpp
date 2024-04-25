/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:23:28 by hrobin            #+#    #+#             */
/*   Updated: 2024/03/25 18:39:41 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include <exception>

template <typename T>
void	swap( T &s1, T &s2 ) {
	T	swop;
	swop = s1;
	s1 = s2;
	s2 = swop;
}


template <typename T>
T min(T a, T b)
{
	if ( a == b)
		return (a);
	else
		return ((a<b) ? a : b);
}

template <typename T>
T max(T a, T b)
{
	if ( a == b)
		return (b);
	else
		return ((a>b) ? a : b);
}
