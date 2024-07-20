#include <iostream>

using namespace std;

int main()
{
    char str[256];
    cout << "Enter some string: ";
    cin.getline(str, 256);
    int words = 1;
    bool space = false;

    for (int character = 0; str[character] != 0; ++character) {
        if (str[character] < 'A' || str[character] > 'z') {
            if (!space) {
                ++words;
                space = true;
            }
        } else
            space = false;

    }

    cout << "Number of words: " << words << endl;

    return 0;
}
