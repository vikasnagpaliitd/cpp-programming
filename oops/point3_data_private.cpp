// Copyright: Vikas Nagpal (Anuttara Learning)
//Demonstrates : Make data private, concept of this pointer
#include <iostream>
using namespace std;
class Point
{
    private:
        int x;
        int y;

    public:

    Point(int ax, int ay) // Ques: what if we wish to use x and y as arguments names?
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

    p1->display();

    delete p1; 

    return 0;
}