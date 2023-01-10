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
        x = ax;
        y = ay;
    }

    void display()
    {
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    }

};

int main()
{
    Point *p1;

    p1 = new Point(11, 21);

    p1->display(); // Notice -> instead of .

    delete p1; // Notice the necessity of freeing resources

    return 0;
}
