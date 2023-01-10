//Demonstrates : Overloaded function
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
	void display(string name);  // Note: pre-built class string (Ques: should we prefer string or char* ? )


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

    cout << "Calling display without argument" << endl;
    p1->display(); 
	
	cout << "Calling display with name argument" << endl;
    p1->display("p1"); 
	
	//Ques: Can two overloaded functions differ only in return type?

    delete p1;

    return 0;
}
