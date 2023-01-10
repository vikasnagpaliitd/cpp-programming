//Demonstrates : Defining - operator using friend
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
	
	//Defining + operator using member function
	
	Point operator+(const Point& other) const
	{
		return Point(this->x + other.x, 
			this->y + other.y);
		
	}
	
	Point operator+(int other) const
	{
		return Point(this->x + other, 
			this->y);
		
	}
	


    void display(); 
	void display(string name);  
	
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
	return Point(first.x - second.x,
		first.y - second.y);
}

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
	Point o2(20,22);

	Point o3 = o1 + o2 + 100;
	
	//Ques: how to enable 5+o1 calculation?
	

	
    o1.display("o1(10,11)");
	o2.display("o2(20,22)");
	o3.display("o3=o1+o2+100");

    return 0;
}
