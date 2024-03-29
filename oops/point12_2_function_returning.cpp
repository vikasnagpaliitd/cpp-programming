//Demonstrates : Returning objects from functions : by value, by reference, by const reference, by pointer
#include <iostream>
using namespace std;

// Point in 2D plane having X axis and Y axis
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


    void display() const; 
	void display(string name) const;  
	
	// Set values
	void set_values(int x=10, int y=20)
	{
		this->x = x;
		this->y = y;
	}
	
	~Point()
	{
		cout << "Destructor called" << endl;
	}
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

Point do_something()
//Point& do_something()
//Point* do_something()
{
	cout << "do_something: called" << endl;
	Point local(100,200); // Ques : can it be correct to return local variable's pointer or reference?
                          // Ques : when can it be correct to return a pointer/reference?
	local.display("local in do_something");
	return local;
}

int main()
{
	Point obj = do_something();
	obj.display("obj in main");

    //do_something().display();

    return 0;
}
