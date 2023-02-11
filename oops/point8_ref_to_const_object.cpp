//Demonstrates : One can mark a method 'const' indicating that it can be 
// safely called on const objects or on const references.
#include <iostream>
using namespace std;

// Point in 2D plane having X axis and Y axis
class Point
{
    private:
        int x;
        int y;

    public:

    Point(int ax, int ay)
    {
        x = ax;
        y = ay;
    }

    void display() const; 
    void display (string name) const;
	//void display (string name) const;  
	
	// Set Values
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
//void Point::display (string name) const
void Point::display (string name) const
{
	
    cout << name << ":" << "x = " << x << endl;
    cout << name << ":" << "y = " << y << endl;
	
}

int main()
{
    Point o1(100, 200);
	const Point &r1 = o1; // const reference (reference to const object)
		
	o1.display("o1 values");
	r1.display("r1 values"); // Ques: why it gives an error?
	
	// Ques: how to inform compiler that a function is safe to be called on const objects?
	// Ques: what if after making such commitment, the function  tries to modify object?
	// Ques: how do constant objects behave? Which member functions are allowed to be callled, and which not.
    return 0;
}
