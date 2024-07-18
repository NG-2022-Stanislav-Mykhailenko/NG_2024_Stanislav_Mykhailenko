#include <iostream>

using namespace std;

int main()
{
    char str[256];
    cout << "Enter some string: ";
    cin.getline(str, 256);
    int words = 1;

    for (int character = 0; character < 256; ++character) {
        if (str[character] == 0)
            break;
        else if (str[character] < 'A' || str[character] > 'z')
            ++words;
    }

    cout << "Number of words: " << words << endl;

    return 0;
}
