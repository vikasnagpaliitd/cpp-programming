#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

class Point
{
	int x, y;

	public:
	Point(int ax, int ay): x(ax), y(ay)
	{
		cout << "Constructor:Point(" << x << ", " << y << ")" << endl;
	}
	Point(const Point& obj) : x(obj.x), y(obj.y)
	{
		cout << "Copy Constructor:Point(" << x << ", " << y << ")" << endl;
	}
	~Point()
	{
		cout << "Destructor:Point(" << x << ", " << y << ")" << endl;
	}
	friend ostream& operator<<(ostream& out_stream, const Point&obj);

};

ostream& operator<<(ostream& out_stream, const Point&obj)
{
    out_stream << "(" << obj.x << ", " << obj.y << ")" ;
    return out_stream;
}


template <typename T>
void print(const T& cnt)
{
	cout << "[ ";
	for (const auto& i : cnt)
		cout << i << " ";
	cout << " ]" << endl;
}

int main()
{
	list<Point> l1;


	cout << "At beginning:" << endl;	
	print(l1);

	l1.insert(l1.begin(), Point(1,2));
	cout << "After insert Point(1,2):" << endl;	
	print(l1);

	l1.insert(l1.begin(), Point(3,4));
	cout << "After insert Point(3,4):" << endl;	
	print(l1);

	l1.insert(l1.begin(), Point(5,6));
	cout << "After insert Point(5,6):" << endl;	
	print(l1);

	l1.emplace(l1.begin(), 7,8);
	cout << "After emplace(l1.begin(),7,8):" << endl;	
	print(l1);

	list<Point>::iterator iter = l1.begin();
	advance(iter, 3);

	l1.emplace(iter, Point(-1,-2));
	cout << "After emplace(l1.begin() advanced by 3,Point(-1,-2):" << endl;	
	print(l1);

	l1.emplace_back(88,89); // emplace_back: at the end
	cout << "After emplace_back(88,89):" << endl;	
	print(l1);

	l1.emplace_front(18,19); // emplace_back: at the end
	cout << "After emplace_front(18,19):" << endl;	
	print(l1);


	return 0;
}
