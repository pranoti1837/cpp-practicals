
#include <iostream>
using namespace std;

// Base class
class Person
{
public:
    string name;

    void getName()
    {
        cout << "Enter name: ";
        cin >> name;
    }

    void displayName()
    {
        cout << "Name: " << name << endl;
    }
};

// Single inheritance
class Student : public Person
{
public:
    int rollNo;

    void getRollNo()
    {
        cout << "Enter roll number: ";
        cin >> rollNo;
    }

    void displayStudent()
    {
        displayName();
        cout << "Roll Number: " << rollNo << endl;
    }
};

// Multilevel inheritance
class Result : public Student
{
public:
    int marks;

    void getMarks()
    {
        cout << "Enter marks: ";
        cin >> marks;
    }

    void displayResult()
    {
        displayStudent();
        cout << "Marks: " << marks << endl;
    }
};

int main()
{
    Result s;

    s.getName();
    s.getRollNo();
    s.getMarks();

    cout << "\nStudent Details:\n";
    s.displayResult();

    return 0;
}
