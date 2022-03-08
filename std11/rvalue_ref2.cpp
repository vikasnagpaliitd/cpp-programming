// Copyright: Vikas Nagpal (Anuttara Learning)
#include <iostream>
using namespace std;


class Point
{
	private:
	int x,y;

	public:
	Point(int ax, int ay) : x(ax), y(ay) { cout << "Constructor:Point: x = " << x << ", y = " << y << endl;}
	void display(string name) const { cout << "Display:Point: " << name << ": x = " << x << ", y = " << y << endl;}
	void set_values(int ax, int ay) { 
										x = ax; y = ay;
										cout << "Display:set_values: " << ": x = " << x << ", y = " << y << endl;
									}
	~Point() { cout << "Destructor:Point: x = " << x << ", y = " << y << endl;}
		
};

int main()
{

	//Point p1(3,4);
	//Point&& rvref1 = p1; // does not compile

	Point&& rvref1 = Point(5,6); // Object lives till the reference goes out of scope
	const Point& cref = rvref1;

	Point& ref2 = rvref1; // It does compile! rvref1 is an lvalue. All named variables are so.
	cout << "rvref1 = " << &rvref1 << endl;
	cout << "cref  = " << &cref << endl;
	rvref1.set_values(11,12);
	rvref1.display("rvref1");
	cref.display("cref");
	ref2.display("ref2");
    return 0;
}

