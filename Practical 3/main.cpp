
#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    string name;
    int age;

public:
    // Default constructor
    Student()
    {
        name = "Unknown";
        age = 0;
    }

    // Parameterized constructor
    Student(string n, int a)
    {
        name = n;
        age = a;
    }

    // Copy constructor
    Student(const Student &s)
    {
        name = s.name;
        age = s.age;
    }

    // Destructor
    ~Student()
    {
        cout << "Object destroyed: " << name << endl;
    }

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

int main()
{
    Student s1;
    Student s2("Pranoti", 19);
    Student s3(s2);

    cout << "Student 1:" << endl;
    s1.display();

    cout << "\nStudent 2:" << endl;
    s2.display();

    cout << "\nStudent 3 (Copied):" << endl;
    s3.display();

    return 0;
}
