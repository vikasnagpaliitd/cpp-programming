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
	unique_ptr<Matrix> uptr1(new Matrix(6,6) );

	Matrix m1 = *uptr1; //operator*
	m1.display();
	uptr1->display(); //operator->


	// Type conversion?
	//unique_ptr<Matrix> uptr3 = new Matrix(6,6); // does not compile as constructor is explicit
	//unique_ptr<Matrix> uptr3 =(unique_ptr<Matrix>) new Matrix(6,6); // works


	// Copy Constructor?
	//unique_ptr<Matrix> uptr4(uptr1); // Does not compile // error: use of deleted function


	// Move Constructor: Transfer of ownership. Source becomes invalid
	unique_ptr<Matrix> uptr2(std::move(uptr1)); // Move constructor
	if (uptr2)
	{
		cout << "After uptr1 moved to uptr2" << endl;
		uptr2->display();
	}

	if (!uptr1)
		cout << "uptr1 is now not true" << endl;
	if (uptr1 == nullptr)
		cout << "uptr1 == nullptr" << endl;


	// Assignment operator?
	unique_ptr<Matrix> uptr5;
	//uptr5 = uptr2; // error: use of deleted function // No copy assign op
	uptr5 = std::move(uptr2); // Move Assign works

	return 0;
}
