// Copyright: Vikas Nagpal (Anuttara Learning)
//Demonstrates : Default Constructor
#include <iostream>
using namespace std;
class Point
{
    private:
        int x;
        int y;

    public:

	// Note: if we dont provide a any constructor, compiler provides a default constructor. 

    Point(int ax=5, int ay=10)
    {
        x = ax;
        y = ay;
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
    //Point o1; // works : default constructor called with no arguments
	//Point o1();// Caution: interpreted as function

	
	Point *p1 = new Point();

    //o1.display("o1");
	p1->display("p1");	
	
	delete p1;

    return 0;
}