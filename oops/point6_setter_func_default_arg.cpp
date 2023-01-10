//Demonstrates : Setter function, default parameters
#include <iostream>
using namespace std;
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

    void display(); 
	void display(string name);  
	
	// Notice: concept of default parameters for functions
	void set_values(int x=10, int y=20) // Ques: is to good to use getter and setter functions?
	{
		this->x = x;
		this->y = y;
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
    Point *p1;

    p1 = new Point(11, 21);

    
    p1->display("initial"); 
	
	p1->set_values(111, 222);
    p1->display("after set_values(111,222)"); 

	p1->set_values(333);
    p1->display("after set_values(333)"); 

	p1->set_values();
    p1->display("after set_values()"); 

	//Ques: Can a non-default parameter come after default param?

    delete p1; 

    return 0;
}
