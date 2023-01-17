//Demonstrates : Make data private, concept of this pointer
#include <iostream>
using namespace std;

class Point
{
    private:
        int x;
        int y;

    public:

    // Ques: what if we wish to use x and y as arguments names?
    // Ans: use "this", which is a pointer to the current objct whose method is called
    Point(int ax, int ay) 
    {
        x = ax;
        y = ay;
    }

    // Point(int x, int y) 
    // {
    //     this->x = x;
    //     this->y = y;
    // }

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
