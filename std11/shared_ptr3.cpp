// Deletion of object when ref count reaches 0 due to assign/reset
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
	shared_ptr<Matrix> sptr1(new Matrix(6,6) );
	shared_ptr<Matrix> sptr8(new Matrix(8,8) );
	Matrix *ptr2 = new Matrix(7,7);

	cout << "sptr1.use_count() = " << sptr1.use_count() << endl;

#if 1
	//sptr1 = nullptr; // Assigned nullptr
	sptr1 = sptr8; //Assigned some other shared pointer
	cout << "sptr1 was assigned " << endl;
	cout << "sptr1.use_count() = " << sptr1.use_count() << endl;
#endif

#if 0
	sptr1.reset(ptr2); // reset to contain some other raw pointer
	cout << "after sptr1.reset(ptr2)" << endl;
	cout << "sptr1.use_count() = " << sptr1.use_count() << endl;
#endif


	return 0;
}
