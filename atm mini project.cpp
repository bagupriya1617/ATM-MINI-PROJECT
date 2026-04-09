#include <iostream>
using namespace std;

class ATM {
private:
    double balance;

public:
    ATM(double initialBalance = 0.0) {
        balance = initialBalance;
    }

    void checkBalance() {
        cout << "Your current balance is: $" << balance << endl;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: $" << amount << endl;
        } else if (amount > balance) {
            cout << "Insufficient funds!" << endl;
        } else {
            cout << "Invalid withdrawal amount!" << endl;
        }
    }
};

int main() {
    ATM myATM(100.0); // Start with $100 balance
    int choice;
    double amount;

    do {
        cout << "\n--- SimpleATM Menu ---\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            myATM.checkBalance();
            break;
        case 2:
            cout << "Enter amount to deposit: ";
            cin >> amount;
            myATM.deposit(amount);
            break;
        case 3:
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            myATM.withdraw(amount);
            break;
        case 4:
            cout << "Thank you for using SimpleATM. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
