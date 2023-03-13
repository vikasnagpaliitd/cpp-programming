// Should we have reference OR pointer to shared pointers? No. rather use raw pointers using .get()
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

//Note: take shared pointer by reference. In general a bad idea
void func2(shared_ptr<Matrix>& argfunc2)
{
	cout << "func2:argfunc2.use_count() = " << argfunc2.use_count() << endl;
}
void func1(shared_ptr<Matrix>& argfunc1)
{
	cout << "func1:before:func2:argfunc1.use_count() = " << argfunc1.use_count() << endl;
	func2(argfunc1);
	cout << "func1:after:func2:argfunc1.use_count() = " << argfunc1.use_count() << endl;
}

int main()
{

	shared_ptr<Matrix> sptr1 = make_shared<Matrix>(6,6);
	cout << "main:before:func1:sptr1.use_count() = " << sptr1.use_count() << endl;
	func1(sptr1);
	cout << "main:after:func1:sptr1.use_count() = " << sptr1.use_count() << endl;

	return 0;
}
