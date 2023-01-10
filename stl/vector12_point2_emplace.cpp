#include <iostream>
#include <vector>
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
	vector<Point> v1;


	cout << "At beginning:" << endl;	
	print(v1);

	v1.insert(v1.begin(), Point(1,2));
	cout << "After insert Point(1,2):" << endl;	
	print(v1);

	v1.insert(v1.begin(), Point(3,4));
	cout << "After insert Point(3,4):" << endl;	
	print(v1);

	v1.insert(v1.begin(), Point(5,6));
	cout << "After insert Point(5,6):" << endl;	
	print(v1);

	v1.emplace(v1.begin()+1, 7,8);
	cout << "After emplace(v1.begin()+1,7,8):" << endl;	
	print(v1);

	v1.emplace(v1.begin(), Point(9,10));
	cout << "After emplace(v1.begin(),Point(9,10):" << endl;	
	print(v1);

	v1.emplace_back(88,89); // emplace_back: at the end
	cout << "After emplace_back(88,89):" << endl;	
	print(v1);


	return 0;
}
