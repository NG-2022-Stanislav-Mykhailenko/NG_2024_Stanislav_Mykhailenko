#include <iostream>

using namespace std;

int main()
{
    char str[256];
    cout << "Enter some string: ";
    cin.getline(str, 256);
    int words = 0;
    bool space = false;

    for (int character = 0; str[character] != 0; ++character) {
        if (str[character] < 'A' || str[character] > 'z') {
            if (!space && words != 0) {
                ++words;
                space = true;
            }
        } else {
            space = false;
            if (words == 0)
                ++words;
        }

    }

    cout << "Number of words: " << words << endl;

    return 0;
}
