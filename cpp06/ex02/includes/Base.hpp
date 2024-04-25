/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:30:26 by hrobin            #+#    #+#             */
/*   Updated: 2024/03/25 12:30:30 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <random>
# include <iostream>

class Base {
	public:
		virtual ~Base();
};

class A : public Base {};

class B : public Base {};

class C : public Base {};
