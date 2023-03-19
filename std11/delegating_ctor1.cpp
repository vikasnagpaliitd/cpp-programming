//Demonstrates : Delegating constructors
#include <iostream>
using namespace std;

// Point in 2D plane having X axis and Y axis
class Point
{
    private:
        int x;
        int y;

    public:

    // Ques: Can we achieve below three effects by using single constructor?
    Point(int ax, int ay) : x(ax), y(ay)
    {
        cout << "Target constructor" << endl;   
    }
	
    Point(int ax) : Point(ax, 0)
    //Point(int ax) : Point(ax, 0), x(11) // Error: If delegating ctor, only 1 element in member initialization list
    {
        cout << "After target constructor, delegating constructor continues" << endl;   
    }
};


int main()
{
    Point p1(10); 

    return 0;
}
