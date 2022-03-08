// Copyright: Vikas Nagpal (Anuttara Learning)
// Resetting unique pointer to  point somewhere else
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
		cout << "this = " << this << endl;
		cout << "display():Matrix: " << x << ", " << y << endl; 
	}

};

int main()
{

	unique_ptr<Matrix> uptr1 = make_unique<Matrix>(7,7); 
	//unique_ptr<Matrix> uptr1; // unique ptr need not be initialized

	uptr1->display(); // Ques:What if member is accessed without initializing uptr1?

	uptr1.reset(new Matrix(9,9));
	//uptr1.reset(nullptr);

	cout << "after reset() " << endl;
	uptr1->display();

	return 0;
}
