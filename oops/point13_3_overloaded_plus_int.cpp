//Demonstrates : Achieving plus + with int 
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
	
	Point operator+(const Point& other) const
	{
		return Point(this->x + other.x, this->y + other.y);
	}

    //Way1: overload operator+ so that it accepts integer too	
	Point operator+(int val) const
	{
		return Point(this->x + val, this->y);
	}

    void display() const; 
	void display(string name) const;  
	
	// Set values
	void set_values(int x=10, int y=20)
	{
		this->x = x;
		this->y = y;
	}

    //friend function
	friend Point operator-(const Point& first, const Point& second);
};

Point operator-(const Point& first, const Point& second)
{
	return Point(first.x - second.x, first.y - second.y);
}

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

	Point o3 = o1 + o2 + 100;
	
	//Ques: how to enable 5+o1 calculation?
	
    o1.display("o1(10,11)");
	o2.display("o2(20,22)");
	o3.display("o3=o1+o2+100");

    return 0;
}
