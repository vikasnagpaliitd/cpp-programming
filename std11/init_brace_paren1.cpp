//Demonstrates : Initialization with brance or parenthesis
#include <iostream>
using namespace std;

// Point in 2D plane having X axis and Y axis
class Point
{
    private:
        int x;
        int y;
    public:


    Point(int ax=0, int ay=0) : x{ax}, y{ay}
    {
		cout << "Parameterized constructor called" << endl;
    }

    void display() const; 
};

void Point::display() const
{
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
}

int main()
{
    Point o1(10,11); 
    int x(2);
    int y{3};
    int z{}; // sets to 0
    int *p1 = new int(5);
    int *p2 = new int{6};
    int arr[] {10,20,30};
	Point o2(o1); 
	
    o1.display();
    cout << x << " " << y << " " << z << " "<< *p1 << " " << *p2 << endl;

    delete p1;
    delete p2;

    return 0;
}
