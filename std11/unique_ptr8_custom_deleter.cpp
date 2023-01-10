// can we pass unique pointer to function
#include <iostream>
#include <memory>
using namespace std;

template<class T>
class MyDeleter
{
	public:
	int data;
	void operator() (T *ptr)
	{
		cout << "MyDeleter" << endl;
		delete ptr;
	}
};

template <class T>
void mydeleter_func(T *ptr)
{
		cout << "mydeleter_func" << endl;
		delete ptr;
}


class Matrix
{
	int x,y;
	public:

	Matrix(int rows=5, int cols=5) :x(rows), y(cols) { cout << "Constructor:Matrix :" << rows << ", " << cols << endl; }
	Matrix(const Matrix& other) :x(other.x), y(other.y) { cout << "Copy Constructor:Matrix" << x << ", " << y << endl; }
	~Matrix() { cout << "Destructor:Matrix" << x << ", " << y << endl; }
	void display() { 
		cout << "display():Matrix" << x << ", " << y << endl; 
	}

};


int main()
{

	unique_ptr<Matrix, MyDeleter<Matrix>> uptr1(new Matrix(9,9));
	unique_ptr<Matrix, void (*)(Matrix*) > uptr2(new Matrix(10,10), mydeleter_func<Matrix> );

	uptr1->display();
	uptr2->display();


	return 0;
}
