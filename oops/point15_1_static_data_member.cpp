//Demonstrates : static data member
#include <iostream>
using namespace std;

// Point in 2D plane having X axis and Y axis
class Point
{
    private:
        int x;
        int y;
	public: // it is not advised to make count public. Done here just for convenience of access.
		static int count; //declaration // count of instances


    public:

    Point(int ax=0, int ay=0)
    {
		cout << "Parameterized constructor called" << endl;
        x = ax;
        y = ay;
		
		count++;
    }
	
	Point(const Point& obj)
	{
		cout << "Copy constructor called" << endl;
		x = obj.x;
		y = obj.y;
		
		count++;
	}
	
	Point operator+(const Point& other) const
	{
		return Point(this->x + other.x, this->y + other.y);
	}
	
	Point operator+(int other) const
	{
		return Point(this->x + other, this->y);
	}
	
	Point& operator = (const Point &other)
	{
		cout << "Assignment operator called" << endl;

		this->x = other.x;
		this->y = other.y;
		
		return (*this);
	}

    void display() const; 
	void display(string name) const;  
	
	// Set values
	void set_values(int x=10, int y=20)
	{
		this->x = x;
		this->y = y;
	}
	
	//Typecasting object to integer (Note: we dont give return type)
	operator int() const{
		return this->x;
	}
	
	~Point()
	{
		cout << "Destructor called" << endl;
		count--;
	}

    //friend functions
	friend Point operator-(const Point& first, const Point& second);
	friend ostream& operator<<(ostream& out_stream, const Point&obj);
	friend istream& operator>>(istream& input_stream, Point&obj);
};

int Point::count = 0; // definition

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

ostream& operator<<(ostream& out_stream, const Point&obj)
{
	out_stream << "operator<<: " << " x = " << obj.x << endl;
	out_stream << "operator<<: " << " y = " << obj.y << endl;
	return out_stream;
}

istream& operator>>(istream& input_stream, Point&obj) // Note: we did not use const Point&
{
	input_stream >> obj.x >> obj.y;

	return input_stream;
}

int main()
{
    Point o1(10,20); 
	
	cout << "After o1, Point::count = " << Point::count << endl;

	Point o2(o1); // copy constructor or assignment operator?
	cout << "After o2, Point::count = " << Point::count << endl;
	
	Point *p3 = new Point(o2);
	cout << "After p3, Point::count = " << Point::count << endl;
	
	delete p3;
	cout << "After delete p3, Point::count = " << Point::count << endl;
	
	// Notice that (same) static member data is accessible via objects as well
	cout << "After delete p3, o1.count = " << o1.count << endl;

    cout << o2;
    return 0;
}
