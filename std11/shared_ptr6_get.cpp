// get() to get raw pointer
#include <iostream>
#include <memory>
using namespace std;

class Matrix
{
	public:

	Matrix(int rows=5, int cols=5) { cout << "Constructor:Matrix" << endl; }
	Matrix(const Matrix& other) { cout << "Copy Constructor:Matrix" << endl; }
	~Matrix() { cout << "Destructor:Matrix" << endl; }
	void display() { cout << "display():Matrix" << endl; }

};

int main()
{
	Matrix *ptr = new Matrix(4,4);
	shared_ptr<Matrix> sptr1(ptr);

	cout << "ptr         == " << ptr << endl;
	cout << "sptr1.get() == " << sptr1.get() << endl; // When would you use get()?


	return 0;
}
