#include <iostream>

using namespace std;

int main()
{
    int numbers[5];
    int max = 0;
    for (int number = 0; number < 5; ++number) {
        cout << "Enter amount in " << number + 1 << " row: ";
        cin >> numbers[number];
        if (numbers[number] > max)
            max = numbers[number];
    }

    for (int iteration = 0; iteration < max; ++iteration) {
        for (int number = 0; number < 5; ++number) {
            if (iteration < numbers[number])
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}
