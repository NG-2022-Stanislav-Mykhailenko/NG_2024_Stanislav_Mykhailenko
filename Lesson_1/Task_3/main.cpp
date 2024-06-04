#include <iostream>

int main()
{
    int money = 0;
    std::cout << "How much money do you earn? ";
    std::cin >> money;

    if (money < 1000)
        std::cout << "Work more. ";
    if (money > 1000) {
        if (money > 1000000)
            std::cout << "You are a millionaire. ";
        if (money < 1000000)
            std::cout << "You work great. ";
    }

    std::cout << "You are doing great!" << std::endl;

    return 0;
}
