//Demonstrates : Default Constructor
#include <iostream>
using namespace std;

class Point
{
    private:
        int x;
        int y;

    public:

	// Note: if we dont provide any constructor, compiler provides a default constructor.
    // Default constuctor does default initialization of members
    // i.e. calling defult constructor for nested objects. Doing nothing for int. etc. 
//#if 0 // experiment3: if we dont provide constructor, compiler provides default constructor
    //Point(int ax, int ay) // experiment2: compiler will not provide default ctor as we have provided a ctor
    Point(int ax=5, int ay=10) // experiment1: default ctor
    {
        x = ax;
        y = ay;
    }
//#endif

    void display(); 
	void display(string name);  
	
	// Set values
	void set_values(int x=10, int y=20)
	{
		this->x = x;
		this->y = y;
	}
};

//display with no argument
void Point::display()
{
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
}

//display with name argument
void Point::display(string name)
{
	
    cout << name << ":" << "x = " << x << endl;
    cout << name << ":" << "y = " << y << endl;
}

int main()
{
    //Point o1; // works : default constructor called with no arguments
	//Point o1();// Caution: interpreted as function

	
	Point *p1 = new Point();

    //o1.display("o1");
	p1->display("p1");	
	
	delete p1;

    return 0;
}
