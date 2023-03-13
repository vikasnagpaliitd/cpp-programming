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

	Matrix m1 = *sptr1; //operator*

	m1.display();
	sptr1->display(); //operator->
	cout << "sptr1.use_count() = " << sptr1.use_count() << endl;



	// Type conversion?
	//shared_ptr<Matrix> uptr3 = new Matrix(6,6); // does not compile as constructor is explicit
	//shared_ptr<Matrix> uptr31 =(shared_ptr<Matrix>) new Matrix(6,6); // works
	//shared_ptr<Matrix> uptr32 =shared_ptr<Matrix>( new Matrix(6,6)); // works

	shared_ptr<Matrix> sptr2;
	//shared_ptr<Matrix> sptr2 = nullptr;
	cout << "sptr2.use_count() = " << sptr2.use_count() << endl;

	//sptr2 = nullptr;
	sptr2 = NULL;

    if (!sptr2)
		cout << "sptr2 is not true" << endl;

    if (sptr2 == nullptr)
		cout << "sptr2 == nullptr" << endl;

    if (sptr2 == NULL)
		cout << "sptr2 == NULL" << endl;

	return 0;
}
