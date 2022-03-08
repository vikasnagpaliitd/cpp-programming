// Copyright: Vikas Nagpal (Anuttara Learning)
//Demonstrates : Shape is base class. Line and Rectangle inherit from it
 
#include <iostream>
using namespace std;


class Shape 
{
	private:
	string label; // Label shown for different shapes
	
	public:
	Shape(string alabel) : label(alabel)
	{
		cout << "Shape Constructor called" << endl;
	}

	virtual void draw() = 0; // pure virtual function

	virtual ~Shape()
	//~Shape()
	{
		cout << "Shape Destructor called" << endl;
	}
};

class Line : public Shape 
{
	private:
		// Normally, Line will add data to store endpoints. Not shown here.
		
	public:
		Line(string alabel) :  Shape(alabel)
		{
			cout << "Line's constructor called" << endl;

		}

		void draw()
		{
			cout << "Line::draw() called" << endl;
		}

		~Line()
		{
			cout << "Line's destructor called" << endl;
		}		
};

class Rectangle : public Shape 
{
	private:
		// Normally, Rectangle will add data to store endpoints. Not shown here.
		
	public:
		Rectangle(string alabel) :  Shape(alabel)
		{
			cout << "Rectangle's constructor called" << endl;

		}
		void draw()
		{
			cout << "Rectangle::draw() called" << endl;
		}
		~Rectangle()
		{
			cout << "Rectangle's destructor called" << endl;
		}		
};

int main()
{

	Shape *s1 = new Line("line1");
    s1->draw();
	delete s1;

	cout << endl;

	Shape *s2 = new Rectangle("rectangle1");
    s2->draw();
	delete s2;


	//Shape *s3 = new Shape("shape1"); // Ques: will it work?

	//Ques: if Line does not define draw, will we be able to instantiate it?

    return 0;
}
