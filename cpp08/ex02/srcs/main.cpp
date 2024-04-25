/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:28:14 by hrobin            #+#    #+#             */
/*   Updated: 2024/04/04 18:11:52 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{

	std::cout << "╔═════ஓ๑♡๑ஓ═════╗" << std::endl;
	std::cout << "   MutantStack" << std::endl;


	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);

	std::cout << "╚═════ஓ๑♡๑ஓ═════╝" << std::endl;
	std::cout << std::endl;

	std::cout << "╔═════ஓ๑♡๑ஓ═════╗" << std::endl;
	std::cout << "       List" << std::endl;

	std::list<int> list;
    list.push_front(5);
    list.push_front(17);
    std::cout << list.front() << std::endl;
    list.pop_front();
    std::cout << list.size() << std::endl;
    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    list.push_back(0);
    std::list<int>::iterator it2 = list.begin();
    std::list<int>::iterator ite2 = list.end();
    ++it2;
    --it2;
    while (it2 != ite2)
    {
        std::cout << *it2 << std::endl;
        ++it2;
    }

	std::cout << "╚═════ஓ๑♡๑ஓ═════╝" << std::endl;
	std::cout << std::endl;

return 0;
}
