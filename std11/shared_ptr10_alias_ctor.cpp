// Should we have reference OR pointer to shared pointers? No. rather use raw pointers using .get()
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
	//shared_ptr<Matrix> sptr1 = make_shared<Matrix>(6,6); // make_shared does not allow custom deleter
	cout << "main:sptr1.use_count() = " << sptr1.use_count() << endl;

	cout << *ptr_to_member << endl;

	return 0;
}
