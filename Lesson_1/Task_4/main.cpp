#include <iostream>

int main()
{
    float firstNumber = 0;
    float secondNumber = 0;
    float result = 0;
    char operation;

    std::cout << "Enter the first number: ";
    std::cin >> firstNumber;

    std::cout << "Enter the second number: ";
    std::cin >> secondNumber;

    std::cout << "Enter operation: ";
    std::cin >> operation;

    switch (operation) {
        case '+':
            result = firstNumber + secondNumber;
            break;
        case '-':
            result = firstNumber - secondNumber;
            break;
        case '*':
            result = firstNumber * secondNumber;
            break;
        case '/':
            if (secondNumber == 0) {
                std::cout << "Division by zero" << std::endl;
                return 1;
            }
            result = firstNumber / secondNumber;
            break;
        default:
            std::cout << "Unknown operation." << std::endl;
            return 2;
            break;
    }

    std::cout << result << std::endl;

    return 0;
}
