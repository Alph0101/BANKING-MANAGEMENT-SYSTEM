#include <iostream>
#include <string>
using namespace std;

class Bank {
private:
    int acno;
    string name;
    long balance;

public:
    void OpenAccount() {
        cout << "Enter Account Number: ";
        cin >> acno;
        cin.ignore(); // To prevent newline issues with getline
        cout << "Enter Name: ";
        getline(cin, name); // Allows spaces in names
        cout << "Enter Initial Balance: ";
        cin >> balance;
    }

    void ShowAccount() const {
        cout << "\nAccount Number: " << acno << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
    }

    void Deposit() {
        long amt;
        cout << "Enter Amount to Deposit: ";
        cin >> amt;
        balance += amt;
        cout << "Updated Balance: " << balance << endl;
    }

    void Withdraw() {
        long amt;
        cout << "Enter Amount to Withdraw: ";
        cin >> amt;
        if (amt <= balance) {
            balance -= amt;
            cout << "Withdrawal Successful! Updated Balance: " << balance << endl;
        } else {
            cout << "Insufficient Balance!" << endl;
        }
    }

    bool Search(int a) const {
        if (acno == a) {
            ShowAccount();
            return true;
        }
        return false;
    }

    int GetAccountNumber() const {
        return acno;
    }
};

int main() {
    const int totalAccounts = 3;
    Bank C[totalAccounts];

    // Open accounts
    for (int i = 0; i < totalAccounts; i++) {
        cout << "\nOpening Account " << i + 1 << endl;
        C[i].OpenAccount();
    }

    int ch;
    do {
        cout << "\n1: Display All Accounts\n2: Search by Account No\n3: Deposit\n4: Withdraw\n5: Exit\n";
        cout << "Please enter your choice: ";
        cin >> ch;

        int a;
        bool found = false;

        switch (ch) {
            case 1:
                for (int i = 0; i < totalAccounts; i++) {
                    C[i].ShowAccount();
                }
                break;

            case 2:
                cout << "Enter Account Number to Search: ";
                cin >> a;
                for (int i = 0; i < totalAccounts; i++) {
                    if (C[i].Search(a)) {
                        found = true;
                        break;
                    }
                }
                if (!found)
                    cout << "Record Not Found!" << endl;
                break;

            case 3:
                cout << "Enter Account Number to Deposit Amount: ";
                cin >> a;
                for (int i = 0; i < totalAccounts; i++) {
                    if (C[i].GetAccountNumber() == a) {
                        C[i].Deposit();
                        found = true;
                        break;
                    }
                }
                if (!found)
                    cout << "Record Not Found!" << endl;
                break;

            case 4:
                cout << "Enter Account Number to Withdraw Amount: ";
                cin >> a;
                for (int i = 0; i < totalAccounts; i++) {
                    if (C[i].GetAccountNumber() == a) {
                        C[i].Withdraw();
                        found = true;
                        break;
                    }
                }
                if (!found)
                    cout << "Record Not Found!" << endl;
                break;

            case 5:
                cout << "Thank you! Have a nice day!" << endl;
                break;

            default:
                cout << "Invalid Option! Try again." << endl;
        }
    } while (ch != 5);

    return 0;
}
