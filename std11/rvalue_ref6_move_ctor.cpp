//Point : Move constructor 
// Note: please compile with -fno-elide-constructors so that compiler does not optimize copy
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

  // Copy Constructor
	Point(const Point& other) : x(other.x), y(other.y)
	{
		label = new char[strlen(other.label)+1];
		strcpy(label, other.label);
		
		cout << "Copy Constructor:Point: label = " << label << ", x = " << x << ", y = " << y << endl;
	}

	// Move constructor
  // Note: 'other' can not be const rvalue ref
	// Ques : What happens if move constructor is not defined?
#if 1
	Point(Point&& other) : x(other.x), y(other.y) //Better conventional way : std::move
	{
		label = other.label;

		other.label = nullptr;
		
		cout << "Move Constructor:Point: label = " << label << ", x = " << x << ", y = " << y << endl;
	}
#endif

	void display(string name) const { cout << "Display:Point: " << name << ":label = " << label << ", x = " << x << ", y = " << y << endl;}
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


void func(Point p)
{
	p.display("func");
}

int main()
{
	Point p("abc", 10,10);

	// Copy Constructor while passing argument
	func(p);

	//func(std::move(p)); // Move constructor while passing argument

	cout << endl << endl;

	// Move Constructor
	func(Point("xyz", 11,11)); // Move constructor while passing argument

    return 0;
}

