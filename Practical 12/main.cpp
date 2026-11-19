

#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

class StudentPortal
{
private:
    string username = "admin";
    string password = "1234";

public:
    bool login()
    {
        string u, p;

        cout << "\n===== STUDENT PORTAL LOGIN =====\n";
        cout << "Username: ";
        cin >> u;

        cout << "Password: ";
        cin >> p;

        if (u == username && p == password)
        {
            cout << "\nLogin Successful!\n";
            return true;
        }

        cout << "\nInvalid Username or Password!\n";
        return false;
    }

    void addStudent()
    {
        int roll;
        string name;
        float marks;

        cout << "\nEnter Roll Number: ";
        cin >> roll;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter Student Name: ";
        getline(cin, name);

        cout << "Enter Marks: ";
        cin >> marks;

        if (roll <= 0 || marks < 0 || marks > 100)
        {
            cout << "Invalid student details!\n";
            return;
        }

        ofstream file("students.txt", ios::app);

        if (!file)
        {
            cout << "Unable to open file!\n";
            return;
        }

        file << roll << "|" << name << "|" << marks << "\n";
        file.close();

        cout << "Student Added Successfully!\n";
    }

    void displayStudents()
    {
        ifstream file("students.txt");
        string line;

        cout << "\n===== STUDENT RECORDS =====\n";

        if (!file)
        {
            cout << "No records found.\n";
            return;
        }

        while (getline(file, line))
        {
            cout << line << endl;
        }

        file.close();
    }

    void searchStudent()
    {
        int searchRoll;
        int roll;
        string name;
        float marks;
        bool found = false;

        cout << "\nEnter Roll Number: ";
        cin >> searchRoll;

        ifstream file("students.txt");

        if (!file)
        {
            cout << "No records found.\n";
            return;
        }

        while (file >> roll)
        {
            file.ignore();
            getline(file, name, '|');
            file >> marks;
            file.ignore(numeric_limits<streamsize>::max(), '\n');

            if (roll == searchRoll)
            {
                cout << "\nStudent Found!\n";
                cout << "Roll Number: " << roll << endl;
                cout << "Name: " << name << endl;
                cout << "Marks: " << marks << endl;

                found = true;
                break;
            }
        }

        file.close();

        if (!found)
            cout << "Student Not Found!\n";
    }

    void menu()
    {
        int choice;

        do
        {
            cout << "\n===== STUDENT DASHBOARD =====\n";
            cout << "1. Add Student\n";
            cout << "2. Display Students\n";
            cout << "3. Search Student\n";
            cout << "4. Logout\n";

            cout << "Enter Choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                cout << "Logged Out Successfully!\n";
                break;

            default:
                cout << "Invalid Choice!\n";
            }

        } while (choice != 4);
    }
};

int main()
{
    StudentPortal portal;

    if (portal.login())
    {
        portal.menu();
    }

    cout << "\nThank You for Using Student Portal!\n";

    return 0;
}
