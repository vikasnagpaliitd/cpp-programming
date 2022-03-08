// Copyright: Vikas Nagpal (Anuttara Learning)
//Can modify the temporary, unless dealing with const references.
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

void func2(Point&& p)
{
	p.display("func2(Point&&)");
}

void func2(Point& p)
{
	p.display("func2(Point&)");
}

void func1(Point&& p)
{
	p.display("func1(Point&&)");
	p.set_values(100,100);// Can modify the temporary
	//func2(p);
	func2(std::move(p));
}

void func1(Point& p)
{
	p.display("func1(Point&)");
	func2(p);
}

int main()
{
	func1(Point(9,9));

    return 0;
}

