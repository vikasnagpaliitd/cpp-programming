//Demonstrates : Destructor
#include <iostream>
#include <cstring> // Note:for C functions related to string processing

using namespace std;
class Point
{
    private:
        int x;
        int y;
		char *label; // added new field to store label
		//Ques: what is better to use? string or char*? 

    public:

    Point(const char *alabel, int ax=5, int ay=10)
    {
		cout << "Parameterized constructor called" << endl;
		label = new char[strlen(alabel) + 1];
		strcpy(label, alabel);
		
        x = ax;
        y = ay;
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
    cout << name << ":" << "x = " << x << endl;
    cout << name << ":" << "y = " << y << endl;
}


int main()
{
    Point o1("Bangalore", 12, 34);
	
	Point *p1 = new Point("Delhi");


	p1->display("p1");	
	
	delete p1;
	
	cout << "Above destructor was called at time of delete" << endl;

    return 0;
}
