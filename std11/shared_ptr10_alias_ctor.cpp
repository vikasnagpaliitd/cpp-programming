// We might store an internal pointer into a managed object. .get() returns internal pointer. Destructor deletes the object start pointer
#include <iostream>
#include <memory>
using namespace std;

class Matrix
{
	public:
	int x,y;

	Matrix(int rows=5, int cols=5) { x=rows; y=cols;cout << "Constructor:Matrix" << endl; }
	Matrix(const Matrix& other) { cout << "Copy Constructor:Matrix" << endl; }
	~Matrix() { cout << "Destructor:Matrix" << endl; }
	void display() { cout << "display():Matrix" << endl; }

};


int main()
{
	shared_ptr<Matrix> sptr1(new Matrix(6,7));

	shared_ptr<int> ptr_to_member(sptr1, &(sptr1->x));

	cout << "main:sptr1.use_count() = " << sptr1.use_count() << endl;
	cout << "*ptr_to_member = " << *ptr_to_member << endl;

  cout << "&(sptr1->x) = " << &(sptr1->x) << endl;
	cout << "ptr_to_member = " << ptr_to_member << endl;
	cout << "sptr1.get()" << sptr1.get() << endl;

	return 0;
}
