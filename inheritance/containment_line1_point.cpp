//Demonstrates : Line object contains two Point objects
#include <iostream>
using namespace std;

class Point
{
    private:
        int x;
        int y;

    public:

    Point(int ax=0, int ay=0)
    //Point(int ax, int ay)
    {
		cout << "Point's Parameterized constructor called" << endl;
        x = ax;
        y = ay;
    }
	
	Point(const Point& obj)
	{
		cout << "Point's Copy constructor called" << endl;
		x = obj.x;
		y = obj.y;
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
	
    void display(); 
	void display(string name);  
	
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
		cout << "Point's destructor called" << endl;
	}

    //friend function
	friend Point operator-(const Point& first, const Point& second);
	friend ostream& operator<<(ostream& out_stream, const Point&obj);
	friend istream& operator>>(istream& input_stream, Point&obj);
};

Point operator-(const Point& first, const Point& second)
{
	return Point(first.x - second.x, first.y - second.y);
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

ostream& operator<<(ostream& out_stream, const Point&obj)
{
	out_stream << "operator<<: " << " x = " << obj.x << endl;
	out_stream << "operator<<: " << " y = " << obj.y << endl;
	return out_stream;
}

istream& operator>>(istream& input_stream, Point&obj)
{
	input_stream >> obj.x >> obj.y;

	return input_stream;
}


class Line
{
	private:
		Point p1; // Ques: when would storing reference or pointer make more sense?
		Point p2;
		
	public:
		Line(int x1, int y1, int x2, int y2) : p1(x1,y1), p2(x2,y2)
		//Line(int x1, int y1, int x2, int y2)
		{
			cout << "Line's constructor called" << endl;
			//Ques : what gets constructed first : Point or Line?
			//Ques: which is better way : member initialization list or in constructor body
			//p1 = Point(x1,y1);
			//p2 = Point(x2,y2);
		}

		~Line()
		{
			cout << "Line's destructor called" << endl;
		}		
};

int main()
{
	Line l1(10,20,100,200);
    return 0;
}
