#include <cmath>
#include <complex>
#include <iostream>

int main()
{
    float a = 0;
    float b = 0;
    float c = 0;
    float D = 0;

    std::cout << "Enter a: ";
    std::cin >> a;

    std::cout << "Enter b: ";
    std::cin >> b;

    std::cout << "Enter c: ";
    std::cin >> c;

    D = pow(b, 2) - 4 * a * c;

    std::complex<float> root = std::sqrt(std::complex<float>(D));

    std::complex<float> x1 = (-b + root) / (2 * a);
    std::complex<float> x2 = (-b - root) / (2 * a);

    std::cout << "x1 = " << x1 << std::endl;
    std::cout << "x2 = " << x2 << std::endl;

    return 0;
}
