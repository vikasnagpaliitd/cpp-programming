//Demonstrates : Overloaded functions
#include <iostream>
using namespace std;

// Point in 2D plane having X axis and Y axis
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

    void display() const; 
    //int display(); // can not overload based on return types
	void display(string name) const;  // Note: pre-built class string (Ques: should we prefer string or char* ? )
};

//display with no argument
void Point::display() const
{
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
}

//display with name argument
void Point::display(string name) const
{
	
    cout << name << ":" << "x = " << x << endl;
    cout << name << ":" << "y = " << y << endl;
}

int main()
{
    Point *p1;

    p1 = new Point(11, 21);

    cout << "Calling display without argument" << endl;
    p1->display(); 
	
	cout << "Calling display with name argument" << endl;
    p1->display("p1"); 
	
	//Ques: Can two overloaded functions differ only in return type?

    delete p1;

    return 0;
}
