/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:50:22 by hrobin            #+#    #+#             */
/*   Updated: 2024/03/27 15:09:21 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template<typename T, typename Func>
void iter(T* arr, size_t length, Func func) {
    for(size_t i = 0; i < length; ++i) {
        func(arr[i]);
    }
}

template<typename T>
void Print(const T& elem) {
    std::cout << elem << " ";
}
