// Copyright: Vikas Nagpal (Anuttara Learning)
//Demonstrates : Copy constructor
#include <iostream>
using namespace std;
class Point
{
    private:
        int x;
        int y;


    public:


    Point(int ax=0, int ay=0)
    {
		cout << "Parameterized constructor called" << endl;
        x = ax;
        y = ay;
    }
	
	Point(const Point& obj)
	{
		cout << "Copy constructor called" << endl;
		x = obj.x;
		y = obj.y;
	}
	


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
    Point o1(10,11); 
	Point o2(o1); 
	//Point o2 = o1; // Another way of calling copy constructor

	
    o1.display("o1(10,11)");
	o2.display("o2(o1)");

    return 0;
}