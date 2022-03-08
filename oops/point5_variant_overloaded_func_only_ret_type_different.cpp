// Copyright: Vikas Nagpal (Anuttara Learning)
//Demonstrates : Make data private
#include <iostream>
using namespace std;
class Point
{
    private:
        int x;
        int y;

    public:

    Point(int ax, int ay) // Ques: what if we wish to use x and y as arguments names?
    {
        x = ax;
        y = ay;
    }

    void display(); 
	int display();
	void display(string name);  // notice pre-built class string


};

//display with no argument
void Point::display()
{
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
}

//display with no argument
int Point::display()
{
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
	retur 0;
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

    delete p1; // Notice the necessity of freeing resources

    return 0;
}