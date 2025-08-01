#include <iostream>
#include <sstream>
#include <cmath>
#include "MyStack.h"

bool isOperator(const std::string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/" ||
           token == "%" || token == "^" || token == "~";
}

bool isNumber(const std::string& token, double& value) {
    std::istringstream iss(token);
    iss >> value;
    return iss.eof() && !iss.fail();
}

int main() {
    std::string line;
    while (std::getline(std::cin, line)) {
        MyStack stack;
        std::istringstream iss(line);
        std::string token;
        bool error = false;

        while (iss >> token) {
            double value;
            if (isOperator(token)) {
                if (token == "~") {
                    if (stack.is_empty()) {
                        std::cout << "Not enough operands." << std::endl;
                        error = true;
                        break;
                    }
                    double a = stack.pop();
                    stack.push(-a);
                } else {
                    if (stack.is_empty()) {
                        std::cout << "Not enough operands." << std::endl;
                        error = true;
                        break;
                    }
                    double b = stack.pop();
                    if (stack.is_empty()) {
                        std::cout << "Not enough operands." << std::endl;
                        error = true;
                        break;
                    }
                    double a = stack.pop();
                    if ((token == "/" || token == "%") && b == 0.0) {
                        std::cout << "Division by zero." << std::endl;
                        error = true;
                        break;
                    }
                    if (token == "+") stack.push(a + b);
                    else if (token == "-") stack.push(a - b);
                    else if (token == "*") stack.push(a * b);
                    else if (token == "/") stack.push(a / b);
                    else if (token == "%") stack.push(std::fmod(a, b));
                    else if (token == "^") stack.push(std::pow(a, b));
                }
            } else if (isNumber(token, value)) {
                stack.push(value);
            } else {
                std::cout << "Unknown token." << std::endl;
                error = true;
                break;
            }
        }

        if (error) continue;

        if (stack.is_empty()) {
            std::cout << "No expression." << std::endl;
        } else {
            double result = stack.pop();
            if (!stack.is_empty()) {
                std::cout << "Too many operands." << std::endl;
            } else {
                std::cout << "= " << result << std::endl;
            }
        }
    }
    return 0;
}
