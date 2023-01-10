// get() : get the raw pointer
#include <iostream>
#include <memory>
using namespace std;

class Matrix
{
	int x,y;
	public:

	Matrix(int rows=5, int cols=5) :x(rows), y(cols) { cout << "Constructor:Matrix : " << rows << ", " << cols << endl; }
	Matrix(const Matrix& other) :x(other.x), y(other.y) { cout << "Copy Constructor:Matrix: " << x << ", " << y << endl; }
	~Matrix() { cout << "Destructor:Matrix: " << x << ", " << y << endl; }
	void display() { 
		cout << "display():Matrix: " << x << ", " << y << endl; 
	}

};

int main()
{

	Matrix *rawPtr = new Matrix(8,8);
	Matrix *ptr;
	unique_ptr<Matrix> uptr1(rawPtr); 

	cout << "rawPtr = " << rawPtr << endl;
	cout << "&uptr1= " << &uptr1 << endl;

	ptr = uptr1.get();
	cout << "get() returned ptr = " << ptr << endl;
	uptr1->display();
	ptr->display();

	return 0;
}
