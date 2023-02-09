//Demonstrates : dynamic allocation of object
#include <iostream>
using namespace std;

class Point
{
    public:
        int x;
        int y;

    Point(int ax, int ay)
    {
        cout << "Constructor called" << endl;
        x = ax;
        y = ay;
    }

    void display() const
    {
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    }

    ~Point()
    {
        cout << "Destructor called" << endl;
        // nothing to do as no resource allocated by constructor
    }
};

int main()
{
    Point *p1;

    p1 = new Point(11, 21);

    p1->display(); // Same as : (*p1).display()

    delete p1; // Must free resources. No garbage collector in C++

    return 0;
}
