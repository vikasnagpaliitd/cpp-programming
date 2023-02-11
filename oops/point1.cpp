//Demonstrates : class, object, constructor, destructor
#include <iostream>
using namespace std;

// Point in 2D plane having X axis and Y axis
class Point
{
    private:
	
    int x; // Data is normally hidden. Functions are normally public. But not necessary
    int y;

    public:

    Point(int ax, int ay) // Constructor
    {
        cout << "Constructor called" << endl;
        x = ax;
        y = ay;
    }

    // One can mark a method 'const' indicating that it can be 
    // safely called on const objects or on const references.
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
    Point p1(10,20);

    p1.display();

    return 0;
}
