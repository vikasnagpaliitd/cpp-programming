// Copyright: Vikas Nagpal (Anuttara Learning)
// release()
#include <iostream>
#include <memory>
using namespace std;

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

	Matrix *rawPtr = new Matrix(8,8);
	unique_ptr<Matrix> uptr1(rawPtr); 

	cout << "rawPtr of uptr1 = " << uptr1.get() << endl;
	cout << "rawPtr = " << rawPtr << endl;

	rawPtr = uptr1.release(); // after release(), caller is responsible for freeing memory
	//uptr1.release(); // leads to memory leak

	cout << "rawPtr of uptr1 = " << uptr1.get() << endl;
	cout << "rawPtr = " << rawPtr << endl;

	delete rawPtr; // after release(), caller is responsible for freeing memory



	return 0;
}
