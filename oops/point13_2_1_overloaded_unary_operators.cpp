//Demonstrates : Overloading unary prefix/postfix operators using member/friend function
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

    // Binary +	
	Point operator+(const Point& other) const
	{
		return Point(this->x + other.x, this->y + other.y);	
	}

    // unary ++ (prefix)	
	Point& operator++() 
	{
        cout << "Inside operator++() (prefix)" << endl;
		x++; y++;
        return *this;
	}

    // unary ++ (postfix)
	Point operator++(int dummy) 
	{
        cout << "Inside operator++(int) (postfix)" << endl;
		Point   result(x, y);
		x++; y++;
		return result;
	}

    // unary +
	Point operator+() const 
	{
		return *this;
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
	friend Point operator-(const Point& first, const Point& second); // binary -
	friend Point operator-(const Point& obj); // unary - prefix
	friend Point operator--(Point& obj, int dummy); // unary --, postfix
};

//binary -
Point operator-(const Point& first, const Point& second)
{
	return Point(first.x - second.x, first.y - second.y);
}

//unary - prefix
Point operator-(const Point& obj)// unary -
{
	return Point(-obj.x, -obj.y);
}

//unary -- postfix
Point operator--(Point& obj, int dummy) // postfix --
{
	Point result(obj);
 
    obj.x--;
    obj.y--;

    return result;
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
    Point o2;

    o1.display("o1");
    cout<< "-------------------------" << endl; 
    cout << "o2 = o1++" << endl;
	o2 = o1++;
    o1.display("o1");
    o2.display("o2");

   
    cout<< "-------------------------" << endl; 
    cout << "o2 = ++o1" << endl;
	o2 = ++o1;
    o1.display("o1");
    o2.display("o2");
    cout<< "-------------------------" << endl; 
    cout << "o2 = -o1" << endl;
	o2 = -o1;
    o1.display("o1");
    o2.display("o2");
    cout<< "-------------------------" << endl; 
    cout << "o2 = o1--" << endl;
	o2 = o1--;
    o1.display("o1");
    o2.display("o2");
	
    return 0;
}
