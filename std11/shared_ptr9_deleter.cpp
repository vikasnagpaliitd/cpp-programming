// Custom Deleter
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

void my_deleter(Matrix *ptr)
{
	cout << "my custom deleter" << endl;
	delete ptr;
}

int main()
{

	shared_ptr<Matrix> sptr1(new Matrix(6,6), my_deleter);
	//shared_ptr<Matrix> sptr1 = make_shared<Matrix>(6,6); // make_shared does not allow custom deleter
	cout << "main:sptr1.use_count() = " << sptr1.use_count() << endl;

	return 0;
}
