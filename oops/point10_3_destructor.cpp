//Demonstrates : Destructor
#include <iostream>
#include <cstring>
using namespace std;

// Point in 2D plane having X axis and Y axis
class Point
{
    private:
        int x;
        int y;
		char *label; // added new field to store label

    public:

    Point(const char *alabel, int ax=5, int ay=10)
    {
		cout << "Parameterized constructor called" << endl;
		label = new char[strlen(alabel) + 1];
		strcpy(label, alabel);
		
        x = ax;
        y = ay;
    }

    Point(const Point& obj)
    {
        cout << "Copy constructor called" << endl;
        label = new char[strlen(obj.label) + 1];
        strcpy(label,obj.label); // Deep copy

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
		cout << "Destructor called on label:" << label << endl;
		delete [] label;
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

//void do_something(const Point& p)
//void do_something(Point& p)
void do_something(Point p)
//void do_something(Point* ptr)
{
    p.display("arg p");
}


int main()
{
    Point o1("Bangalore", 12, 34);
	
	Point *p1 = new Point("Delhi");


	p1->display("p1");	
	
	delete p1;
	
	cout << "Above destructor was called at time of delete" << endl;

    do_something(o1);

	cout << "do_something() has returned" << endl;


    return 0;
}
