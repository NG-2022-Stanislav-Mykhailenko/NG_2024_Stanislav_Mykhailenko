#include <iostream>

using namespace std;

int main()
{
    int money = 0;
    cout << "How much money do you earn? ";
    cin >> money;

    if (money < 1000)
        cout << "Work more. ";

    if (money > 999)
        if (money < 1001) {
            cout << "Illegal salary." << endl;
            return 1;
        }

    if (money > 1000) {
        if (money > 1000000)
            cout << "You are a millionaire. ";
        if (money < 1000000)
            cout << "You work great. ";
        if (money > 999999)
            if (money < 1000001) {
                cout << "Illegal salary." << endl;
                return 1;
            }
    }

    cout << "You are doing great!" << endl;

    return 0;
}
