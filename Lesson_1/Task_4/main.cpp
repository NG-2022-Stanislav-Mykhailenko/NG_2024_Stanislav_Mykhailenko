#include <iostream>

using namespace std;

int main()
{
    float firstNumber = 0;
    float secondNumber = 0;
    float result = 0;
    char operation = 0;

    cout << "Enter the first number: ";
    cin >> firstNumber;

    cout << "Enter the second number: ";
    cin >> secondNumber;

    cout << "Enter operation: ";
    cin >> operation;

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
                cout << "Division by zero" << endl;
                return 1;
            }
            result = firstNumber / secondNumber;
            break;
        default:
            cout << "Unknown operation." << endl;
            return 2;
            break;
    }

    cout << result << endl;

    return 0;
}
