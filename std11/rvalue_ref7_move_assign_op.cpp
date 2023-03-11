//Point : Move assignment operator
#include <iostream>
#include <cstring>
using namespace std;


class Point
{
	private:
	int x,y;
	char *label; // dynamically allocated storage

	public:
	Point(const char *alabel, int ax, int ay) : x(ax), y(ay) 
	{
		label = new char[strlen(alabel)+1];
		strcpy(label, alabel);
		cout << "Constructor:Point: label = " << label << ", x = " << x << ", y = " << y << endl;
	}

	Point(const Point& other) : x(other.x), y(other.y)
	{
		label = new char[strlen(other.label)+1];
		strcpy(label, other.label);
		
		cout << "Copy Constructor:Point: label = " << label << ", x = " << x << ", y = " << y << endl;
	}

	// Move constructor
	Point(Point&& other) : x(other.x), y(other.y) //Better conventional way : std::move
	{
		label = other.label;

		other.label = nullptr;
		
		cout << "Move Constructor:Point: label = " << label << ", x = " << x << ", y = " << y << endl;
	}

	// Copy assignment operator
	Point& operator=(const Point& other)
	{
		cout << "Copy Assignment operator called" << endl;
		// Check Assignment to self
		if (this == &other)
			return *this;

		// Release resources
		delete [] label;
	
		// Copy resources and values	
		label = new char[strlen(other.label)+1];
		strcpy(label, other.label);
		x = other.x;
		y = other.y;
		
		return *this;
	}
#if 1
	// Move assignment operator
	Point& operator=(Point&& other)
	{
		cout << "Move Assignment operator called" << endl;

		// Not necessary to check Assignment to self
		//if (this == &other)
		//	return *this;

		// Release resources
		delete [] label;
	
		// Move resources and values	
		label = other.label; // steal(move) the resource
		x = other.x;
		y = other.y;

		// Mark resources in moved-from object as null
		other.label = nullptr;
		
		return *this;
	}
#endif

	void display(string name) const { cout << "Display:Point: " << name << ":label = " << (label?label:"moved-from object") << ", x = " << x << ", y = " << y << endl;}
	void set_values(int ax, int ay) { 
										x = ax; y = ay;
										cout << "Display:set_values: " << ": x = " << x << ", y = " << y << endl;
									}
	~Point() { 
		if (label)
			cout << "Destructor:Point: label = " << label << ", x = " << x << ", y = " << y << endl; 
		else
			cout << "Destructor:Point: moved-from object: x = " << x << ", y = " << y << endl; 
		delete [] label;
		}
		
};


int main()
{
	Point p1("abc", 10,10);
	Point p2("xyz", 1, 1);
	p1.display("p1");
	p2.display("p2");

	p2 = p1; // copy assignment operator
	//p2 = Point("temp", 9,9); // Move assignment operator (if defined) 
	//p2 = std::move(p1); // move assignment operator

	cout << "after assignment:" << endl <<endl;
	p1.display("p1");
	p2.display("p2");

    return 0;
}

