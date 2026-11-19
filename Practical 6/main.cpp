
#include <iostream>
using namespace std;

// Base class
class Shape
{
public:
    // Virtual function
    virtual void area()
    {
        cout << "Area of shape" << endl;
    }

    // Pure virtual function
    virtual void display() = 0;
};

// Derived class
class Rectangle : public Shape
{
private:
    int length, breadth;

public:
    Rectangle(int l, int b)
    {
        length = l;
        breadth = b;
    }

    void area() override
    {
        cout << "Area of Rectangle: "
             << length * breadth << endl;
    }

    void display() override
    {
        cout << "This is a Rectangle" << endl;
    }
};

int main()
{
    Rectangle r(10, 5);

    Shape *ptr = &r;

    ptr->display();
    ptr->area();

    return 0;
}
