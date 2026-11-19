
#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    int accountNumber;
    string holderName;
    double balance;

public:
    // Constructor
    BankAccount(int accNo, string name, double amount)
    {
        accountNumber = accNo;
        holderName = name;

        if (amount >= 0)
            balance = amount;
        else
            balance = 0;
    }

    // Deposit function
    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposit successful!" << endl;
        }
        else
            cout << "Invalid amount!" << endl;
    }

    // Withdraw function
    void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Withdrawal successful!" << endl;
        }
        else
            cout << "Invalid withdrawal!" << endl;
    }

    // Display function
    void display()
    {
        cout << "\nAccount Number: " << accountNumber;
        cout << "\nHolder Name: " << holderName;
        cout << "\nBalance: " << balance << endl;
    }
};

int main()
{
    BankAccount account1(101, "Pranoti", 5000);
    BankAccount account2(102, "Amit", 3000);

    cout << "ACCOUNT 1";
    account1.display();

    account1.deposit(1000);
    account1.withdraw(500);
    account1.display();

    cout << "\nACCOUNT 2";
    account2.display();

    account2.deposit(500);
    account2.display();

    return 0;
}
