// Copyright: Vikas Nagpal (Anuttara Learning)
//overloading based on rvalue ref vs lvalue ref 
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


#if 1
void func1(Point&& p)
{
	p.display("func1(Point&&)");
}
#endif

#if 1
void func1(Point& p) // Ques: can we modify the prototype so that temporary objects also get passed?
{
	p.display("func1(Point&)");
}
#endif

int main()
{
	func1(Point(9,9));

	Point p1(1,1);
	func1(p1);

    return 0;
}

