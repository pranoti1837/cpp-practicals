
#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Student
{
public:
    string name;

    Student(string n)
    {
        name = n;
        cout << "Student created: " << name << endl;
    }

    ~Student()
    {
        cout << "Student destroyed: " << name << endl;
    }

    void display()
    {
        cout << "Student Name: " << name << endl;
    }
};

int main()
{
    // Unique pointer
    unique_ptr<Student> s1 =
        make_unique<Student>("Pranoti");

    s1->display();

    // Shared pointer
    shared_ptr<Student> s2 =
        make_shared<Student>("Amit");

    shared_ptr<Student> s3 = s2;

    cout << "Shared pointer count: "
         << s2.use_count() << endl;

    s2->display();

    return 0;
}
