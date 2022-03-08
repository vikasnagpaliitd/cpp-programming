// Copyright: Vikas Nagpal (Anuttara Learning)
//Demonstrates : Object reference
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

    void display(); 
	void display(string name);  
	
	// Set Values
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
    Point o1(100, 200); // object 1
	Point &r1 = o1; // reference 1
	
	cout << "Address of o1 = " << &o1 << endl;
	cout << "Address of r1 = " << &r1 << endl;
	
	
	o1.display("o1 before setting values");
	r1.display("r1 before setting values");
	
	cout << "Calling r1.set_values(199, 299)" << endl;
	r1.set_values(199, 299);
	
	o1.display("o1 after setting values");
	r1.display("r1 after setting values");	 

    return 0;
}