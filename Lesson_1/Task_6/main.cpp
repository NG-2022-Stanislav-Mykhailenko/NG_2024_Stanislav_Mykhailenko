#include <iostream>

int main()
{
    int size = 0;

    std::cout << "Enter size: ";
    std::cin >> size;

    for (int iteration = 0; iteration < size; ++iteration) {
        int spaces = size - iteration - 1;
        int asterisks = 1 + iteration * 2;
        for (int space = 0; space < spaces; ++space)
            std::cout << " ";
        for (int asterisk = 0; asterisk < asterisks; ++asterisk)
            std::cout << "*";
        std::cout << std::endl;
    }

    for (int space = 0; space < size - 1; ++space)
        std::cout << " ";
    std::cout << "*" << std::endl;

    return 0;
}
