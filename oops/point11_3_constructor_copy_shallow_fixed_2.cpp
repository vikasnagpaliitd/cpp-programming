//Demonstrates : Copy constructor : Shallow : fix2 : Maitain reference counts
#include <iostream>
#include <cstring>
using namespace std;

struct refPtr
{
	int count; // Reference count
	char *ptr; // actual data
};

class Point
{
    private:
        int x;
        int y;
		
		//const char *label; 
		struct refPtr *refPtr; // Fix: maintain reference count in addition to pointer
		
    public:
	
    Point(const char *alabel, int ax=5, int ay=10)
    {
		cout << "Parameterized constructor called" << endl;
		refPtr = new struct refPtr;
		refPtr->ptr = new char[strlen(alabel) + 1];
		refPtr->count = 1;
		strcpy(refPtr->ptr,alabel);
		
        x = ax;
        y = ay;
    }

    // Copy constructor	
	Point(const Point& obj)
	{
		cout << "Copy constructor called" << endl;

		refPtr= obj.refPtr;
		refPtr->count++; // increase reference count
		// Ques: what if one object wants to change string content when reference count is > 1

		//Exercise : try achieving the same thing using reference instead of pointer
		
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
		cout << "Destructor called on label:" << refPtr->ptr << endl;
		cout << "Destructor:Reference count :" << refPtr->count << endl;
		refPtr->count --; // Decrease reference count
		if (refPtr->count <= 0)
		{
			cout << "Destructor:Releasing Ptr as well as refPtr struct" << endl;
			delete [] refPtr->ptr;
			delete refPtr;
		}
		else
			cout << "Destructor: not freeing any memory" << endl;
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
	cout << name << ":" << "label = " << refPtr->ptr << endl;
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
