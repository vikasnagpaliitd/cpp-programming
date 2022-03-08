// Copyright: Vikas Nagpal (Anuttara Learning)
// make_unique (C++ 14 onwards), Move constructor, Move assignment operator
#include <iostream>
#include <memory>
using namespace std;

class Matrix
{
	public:

	Matrix(int rows=5, int cols=5) { cout << "Constructor:Matrix :" << rows << ", " << cols << endl; }
	Matrix(const Matrix& other) { cout << "Copy Constructor:Matrix" << endl; }
	~Matrix() { cout << "Destructor:Matrix" << endl; }
	void display() { cout << "display():Matrix" << endl; }

};

int main()
{

	unique_ptr<Matrix> uptr1 = make_unique<Matrix>(7,7);  
	//auto uptr1 = make_unique<Matrix>(7,7);

	uptr1 = make_unique<Matrix>(8,8);
	//uptr1 = nullptr; // will release the pointed object
	//uptr1 = NULL; // will release the pointed object // prefer nullptr
	cout << "after assignment of new value to uptr" << endl;

	return 0;
}
