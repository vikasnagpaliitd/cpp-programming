// Copyright: Vikas Nagpal (Anuttara Learning)
//Demonstrates : const or reference member data
#include <iostream>
using namespace std;
class Point
{
    private:
		const char * const label; // const
        int x;
        int y;
		int &ref;// Reference

    public:

	// Note: Member initialization list : Const & reference must be put in initializer list
	//Ques: can we put ax and ay too in initializer list?
    Point(int ax, int ay,  const char *alabel, int val) : label(alabel), ref(val)
    {
        x = ax;
        y = ay;
		//label = alabel; // Ques: why does it not work?
		//ref = val; // Ques: why does it not work?
    }

    void display(); 
	void display (string name) ;  
	
	// Set Values
	void set_values(int x=10, int y=20)
	{
		this->x = x;
		this->y = y;
		//this->label = "new label"; // Ques:will it work?
	}


};

//display with no argument
void Point::display()
{
	cout << "label = " << label << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
}

//display with name argument
void Point::display (string name) 
{
	cout << name << ":" << "label = " << label << endl;
    cout << name << ":" << "x = " << x << endl;
    cout << name << ":" << "y = " << y << endl;
	
}


int main()
{
	int abc=100;
    Point o1(100, 200, "Delhi", abc);
	
		
	o1.display("o1 values");

    return 0;
}