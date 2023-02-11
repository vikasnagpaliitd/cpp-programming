//Demonstrates : Copy constructor : Shallow : fixed 1 : workaround: assume the pointer is not dynamically allocated
#include <iostream>
#include <cstring>
using namespace std;

// Point in 2D plane having X axis and Y axis
class Point
{
    private:
        int x;
        int y;
		const char *label; // Workaround: fix1: assume label not to be freed as not dynamically allocated
		
    public:

    Point(const char *alabel, int ax=5, int ay=10)
    {
		cout << "Parameterized constructor called" << endl;
		//label = new char[strlen(alabel) + 1];
		//strcpy(label,alabel);
		label = alabel;
		
        x = ax;
        y = ay;
    }

    // Copy constructor	
	Point(const Point& obj)
	{
		cout << "Copy constructor called" << endl;

		label = obj.label; 
		
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
		//delete [] label;  // Soln: Dont free. label is not from heap.
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
	cout << name << ":" << "label = " << label << endl;
    cout << name << ":" << "x = " << x << endl;
    cout << name << ":" << "y = " << y << endl;
}

int main()
{
    Point o1("Bangalore", 12, 34);
	
	Point o2(o1);

	o1.display("o1");
	o2.display("o2");		
	
    return 0;
}
