#include <cmath>
#include <iostream>

int main()
{
    float x = 0;
    float y = 0;
    float N = 0;
    float distance = 0;

    std::cout << "x = ";
    std::cin >> x;

    std::cout << "y = ";
    std::cin >> y;

    std::cout << "N = ";
    std::cin >> N;

    if (x > N || y > N) {
        std::cout << "Beyond radius." << std::endl;
        return 1;
    }

    distance = sqrt(pow(x, 2) + pow(y, 2));

    std::cout << distance << std::endl;

    return 0;
}
