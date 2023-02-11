//Demonstrates : a) using constructor to typecast from int to object
//				b) typecasting object to int 
#include <iostream>
using namespace std;

// Point in 2D plane having X axis and Y axis
class Point
{
    private:
        int x;
        int y;

    public:

    // Note : below constructor can be used to convert int to Point
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
		cout << "Member Binary operator + invoked" << endl;
		return Point(this->x + other.x, this->y + other.y);
	}
	
    void display() const; 
	void display(string name) const;  
	
	// Set values
	void set_values(int x=10, int y=20)
	{
		this->x = x;
		this->y = y;
	}

#if 0
	//Typecasting object to integer (Note: we dont give return type)
	operator int() const{
		return this->x;
	}
#endif

    //friend function
	friend Point operator+(int val, const Point& obj);

};

#if 0
Point operator+(int val, const Point& obj)
{
    cout << "friend operator+ invoked" << endl;
	return Point(val + obj.x, obj.y);
}
#endif

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

	//Point o2 = o1+100;
	//Point o2 = 100+o1;
	Point o2 = (Point)100+o1;
	//Point o2 = Point(100)+o1;
	
	//Ques: how to enable 5+o1 calculation?
	
    o1.display("o1(10,11)");
	o2.display("o2");
	
	//cout << "(int)o2 = " << (int)o2 << endl;

    return 0;
}
