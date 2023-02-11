//Demonstrates : Passing objects to functions : by value, by reference, by const reference, by pointer
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

void do_something(Point obj)
//void do_something(Point &obj)
//void do_something(const Point &obj)
//void do_something(Point *pobj)
{
	cout << "do_something: called" << endl;
	obj.display("obj");
	//pobj->display("*pobj");
}

int main()
{
    Point o1(10,11); 

	do_something(o1);
	//do_something(&o1);

    return 0;
}
