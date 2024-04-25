/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:59:20 by hrobin            #+#    #+#             */
/*   Updated: 2024/04/25 16:33:58 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <set>

// Fonction de tri fusion pour std::vector
void merge(std::vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Fonction de tri fusion pour std::list
void merge(std::list<int>& lst) {
    std::list<int> left, right;
    if (lst.size() <= 1)
        return;

    std::list<int>::size_type middle = lst.size() / 2;

    std::list<int>::iterator it = lst.begin();
    for (std::list<int>::size_type i = 0; i < middle; ++i) {
        left.push_back(*it);
        ++it;
    }
    for (std::list<int>::size_type i = middle; i < lst.size(); ++i) {
        right.push_back(*it);
        ++it;
    }

    merge(left);
    merge(right);

    lst.clear();

    while (!left.empty() && !right.empty()) {
        if (left.front() <= right.front()) {
            lst.push_back(left.front());
            left.pop_front();
        } else {
            lst.push_back(right.front());
            right.pop_front();
        }
    }

    while (!left.empty()) {
        lst.push_back(left.front());
        left.pop_front();
    }

    while (!right.empty()) {
        lst.push_back(right.front());
        right.pop_front();
    }
}

bool hasDuplicate(const std::vector<int>& arr) {
    std::set<int> seen;
    for (size_t i = 0; i < arr.size(); ++i) {
        if (seen.find(arr[i]) != seen.end()) {
            return true;
        }
        seen.insert(arr[i]);
    }
    return false;
}

bool isNumeric(const std::string& str) {
    std::istringstream iss(str);
    int num;
    return (iss >> num) && iss.eof();
}

void printNumbers(const std::vector<int>& numbers, const std::string& message) {
    std::cout << message;
    if (numbers.size() <= 5) {
        for (size_t i = 0; i < numbers.size(); ++i) {
            std::cout << " " << numbers[i];
        }
    } else {
        for (size_t i = 0; i < 5; ++i) {
            std::cout << " " << numbers[i];
        }
        std::cout << " [...]";
    }
    std::cout << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error: No input sequence provided." << std::endl;
        return 1;
    }

    std::vector<int> numbers;
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (!isNumeric(arg)) {
            std::cerr << "Error: Non-numeric input encountered." << std::endl;
            return 1;
        }
        int num = atoi(argv[i]);
        if (num < 0) {
            std::cerr << "Error: Negative integer encountered." << std::endl;
            return 1;
        }
        numbers.push_back(num);
    }

    if (hasDuplicate(numbers)) {
        std::cerr << "Error: Duplicate integer encountered." << std::endl;
        return 1;
    }

    printNumbers(numbers, "Before:");

    std::vector<int> numbers_copy = numbers;
    std::list<int> numbers_list(numbers.begin(), numbers.end());

    clock_t start1 = clock();
    mergeSort(numbers, 0, numbers.size() - 1);
    clock_t end1 = clock();
    double duration1 = (double)(end1 - start1) / CLOCKS_PER_SEC * 1e6;

    clock_t start2 = clock();
    merge(numbers_list);
    clock_t end2 = clock();
    double duration2 = (double)(end2 - start2) / CLOCKS_PER_SEC * 1e6;

    std::vector<int> sorted_numbers_list(numbers_list.begin(), numbers_list.end());

    printNumbers(sorted_numbers_list, "After:");

    std::cout << "Time to process a range of " << numbers.size() << " elements with merge-sort: "
         << duration1 << " us" << std::endl;
    std::cout << "Time to process a range of " << numbers.size() << " elements with custom list sort: "
         << duration2 << " us" << std::endl;

    return 0;
}
