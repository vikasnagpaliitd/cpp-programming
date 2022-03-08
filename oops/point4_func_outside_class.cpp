// Copyright: Vikas Nagpal (Anuttara Learning)
//Demonstrates : Defining function outside class (In big projects, we will need .h and .cpp separate)
#include <iostream>
using namespace std;
class Point
{
    private:
        int x;
        int y;

    public:

    Point(int ax, int ay)
    {
        x = ax;
        y = ay;
    }

    void display(); // declaration


};

//Function defined outside class. Its still a class member
void Point::display()
{
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
}

int main()
{
    Point *p1;

    p1 = new Point(11, 21);

    p1->display();

    delete p1;

    return 0;
}