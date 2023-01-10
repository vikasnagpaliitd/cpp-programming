//Demonstrates : constructor, concept of namespace, use of "using namespace"
#include <iostream>
using namespace std;
class Point
{
    public:
	
    int x; // Ques: is keeping data public, a good idea?
    int y;

    Point(int ax, int ay) // Constructor
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
    Point p1(10,20);

    p1.display();

    return 0;
}
