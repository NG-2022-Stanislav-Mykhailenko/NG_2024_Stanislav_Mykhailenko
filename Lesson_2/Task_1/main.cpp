#include <iostream>

using namespace std;

int main()
{
    int accounts[10];

    for (int account = 0; account < 10; ++account)
        accounts[account] = 0;

    while (true) {
        int action = 0;

        cout << "Enter action (1 - add money, 2 - remove money, 3 - display all balances): ";
        cin >> action;

        if (action == 1 || action == 2) {
            int number = 0;
            int money = 0;
            cout << "Enter account number: ";
            cin >> number;
            if (number >= 0 && number < 10) {
                cout << "Enter the amount of money: ";
                cin >> money;
                if (money > 0) {
                    if (action == 1) {
                        accounts[number] += money;
                        cout << "Money added." << endl;
                    } else if (accounts[number] >= money) {
                        accounts[number] -= money;
                        cout << "Money removed." << endl;
                    } else
                        cout << "Not enough money." << endl;
                } else
                    cout << "The amount must be positive." << endl;
            } else
                cout << "Invalid account number." << endl;
        } else if (action == 3) {
            for (int account = 0; account < 10; ++account)
                cout << "Account " << account << ": " << accounts[account] << endl;
        } else
            cout << "Invalid action." << endl;
    }


    return 0;
}
