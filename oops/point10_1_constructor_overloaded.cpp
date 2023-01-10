//Demonstrates : Overloaded constructors
#include <iostream>
using namespace std;
class Point
{
    private:
        int x;
        int y;

    public:

	 
    // Ques: Can we achieve below three effects by using single constructor?
    Point(int ax, int ay)
    {
        x = ax;
        y = ay;
    }
	
    Point(int ax)
    {
        x = ax;
        y = 0;
    }
	
    Point() // Default constructor
    {
        x = 0;
        y = 0;
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
	Point o2(10); 
	Point o3; 

	
    o1.display("o1(10,11)");
	o2.display("o2(10)");
    o3.display("o3()");
    return 0;
}
