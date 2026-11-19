#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name;
    int mark1, mark2;
    const int PASS_MARK = 40;

    cout << "Enter student name: ";
    getline(cin, name);

    cout << "Enter marks in subject 1: ";
    cin >> mark1;

    cout << "Enter marks in subject 2: ";
    cin >> mark2;

    if ((mark1 >= 0 && mark1 <= 100) &&
        (mark2 >= 0 && mark2 <= 100))
    {
        int total = mark1 + mark2;
        double average = total / 2.0;

        cout << "\nStudent Name: " << name;
        cout << "\nTotal Marks: " << total;
        cout << "\nAverage: " << average;

        if (average >= PASS_MARK)
            cout << "\nResult: Pass";
        else
            cout << "\nResult: Fail";
    }
    else
    {
        cout << "Invalid marks!";
    }

    return 0;
}