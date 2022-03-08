// Copyright: Vikas Nagpal (Anuttara Learning)
//r-value passed to a function behaves as l-value in that function
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
	func2(p);
	//func2(std::move(p));
	//func2(std::forward<Point>(p));
}

void func1(Point& p)
{
	p.display("func1(Point&)");
	func2(p);
}

int main()
{
	func1(Point(9,9));

	//Point p(8,8);
	//func1(p);

    return 0;
}

