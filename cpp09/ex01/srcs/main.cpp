/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:51:26 by hrobin            #+#    #+#             */
/*   Updated: 2024/04/15 20:22:44 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <sstream>
#include <stdexcept>

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool isNumber(char c) {
    return c >= '0' && c <= '9';
}

int stringToInt(const std::string& str) {
    std::stringstream ss(str);
    int result;
    ss >> result;
    return result;
}

int performOperation(int operand1, int operand2, char op) {
    switch (op) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 != 0)
                return operand1 / operand2;
            else
                throw std::runtime_error("Division by zero!");
        default:
            throw std::invalid_argument("Invalid operator!");
    }
}

int evaluateRPN(const std::string& expression) {
    std::stack<int> operands;
    std::stringstream ss(expression);
    std::string token;

    while (ss >> token) {
        if (isNumber(token[0])) {
            operands.push(stringToInt(token));
        } else if (isOperator(token[0])) {
            if (operands.size() < 2) {
                throw std::invalid_argument("Invalid expression!");
            }
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();
            operands.push(performOperation(operand1, operand2, token[0]));
        } else {
            throw std::invalid_argument("Invalid token encountered!");
        }
    }

    if (operands.size() != 1) {
        throw std::invalid_argument("Invalid expression!");
    }

    return operands.top();
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <RPN expression>" << std::endl;
        return 1;
    }

    try {
        int result = evaluateRPN(argv[1]);
        std::cout << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    return 0;
}
