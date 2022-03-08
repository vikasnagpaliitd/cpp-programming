// Copyright: Vikas Nagpal (Anuttara Learning)
// Allocation of array
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

	unique_ptr<Matrix[]> uptr1(new Matrix[2] );

	uptr1[0].display();
	uptr1[1].display();

	// operator* and operator-> are not available
	//uptr1->display();
	//(*uptr1).display();

	return 0;
}
