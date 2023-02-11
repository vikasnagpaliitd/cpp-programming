//Demonstrates : Defining + operator (as a member function)
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
	
	//Defining + operator using member function
	Point operator+(const Point& other) const
	{
		//return Point(this->x + other.x, this->y + other.y);
		return Point(x + other.x, y + other.y);
	}

    void display() const; 
	void display(string name) const;  
	
	// Set values
	void set_values(int x=10, int y=20)
	{
		this->x = x;
		this->y = y;
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

int main()
{
    Point o1(10,11); 
	Point o2(20,22);
	Point o3;

	o3 = o1 + o2;
	//o3 = o1.operator+(o2);
	//o3.operator=(o1.operator+(o2)); // Ques: we didnt define operator=. how does it work?
	
    o1.display("o1(10,11)");
	o2.display("o2(20,22)");
	o3.display("o3=o1+o2");

    return 0;
}
