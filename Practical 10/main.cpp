
#include <iostream>
#include <stdexcept>
using namespace std;

class BankAccount
{
private:
    double balance;

public:
    BankAccount(double b)
    {
        balance = b;
    }

    void withdraw(double amount)
    {
        if (amount <= 0)
            throw invalid_argument("Invalid amount!");

        if (amount > balance)
            throw runtime_error("Insufficient balance!");

        balance -= amount;

        cout << "Withdrawal successful!" << endl;
        cout << "Remaining Balance: " << balance << endl;
    }
};

int main()
{
    BankAccount account(5000);

    try
    {
        account.withdraw(2000);
        account.withdraw(4000);
    }
    catch (const exception &e)
    {
        cout << "Transaction Error: "
             << e.what() << endl;
    }

    return 0;
}
