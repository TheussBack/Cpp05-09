/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 11:30:37 by hrobin            #+#    #+#             */
/*   Updated: 2024/04/04 18:00:59 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <stack>
# include <list>
# include <deque>
#include <iostream>
#include <string>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack() : std::stack<T>() {}
        MutantStack(MutantStack const & src) : std::stack<T>(src) {}
        virtual ~MutantStack() {}

        typedef typename std::deque<T>::iterator iterator;
		iterator begin() {
            return this->c.begin();
        } iterator end() {
            return this->c.end();
        }

};
