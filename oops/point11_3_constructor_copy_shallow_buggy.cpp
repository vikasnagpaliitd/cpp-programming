//Demonstrates : Copy constructor (Shallow copy : buggy)
#include <iostream>
#include <cstring>
using namespace std;
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
		strcpy(label,alabel);
		
        x = ax;
        y = ay;
    }
	
	Point(const Point& obj)
	{
		cout << "Copy constructor called" << endl;
		//label = new char[strlen(obj.label) + 1]; // Deep copy
		//strcpy(label,obj.label);
		label = obj.label; // Ques: do you see any issue given that destructor is freeing the memory?
		
        x = obj.x;
        y = obj.y;

	}



    void display(); 
	void display(string name);  
	
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
void Point::display()
{
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
}

//display with name argument
void Point::display(string name)
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
