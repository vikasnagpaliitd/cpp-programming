// Copy/Move Constructor. Copy/Move Assignment operator
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

	cout << "sptr1.use_count() = " << sptr1.use_count() << endl;

// Please enable one of below copy constructor vs Move constructor blocks
#if 1
	// Copy Constructor : increases reference count;
	shared_ptr<Matrix> sptr2(sptr1); 
    cout << "After Copy Constructor" << endl;
	cout << "sptr1.use_count() = " << sptr1.use_count() << endl;
	cout << "sptr2.use_count() = " << sptr2.use_count() << endl;
#endif

#if 0
	// Move Constructor : does not increase reference count;
	shared_ptr<Matrix> sptr2(move(sptr1)); 
    cout << "After Move Constructor" << endl;
	cout << "sptr1.use_count() = " << sptr1.use_count() << endl;
	cout << "sptr2.use_count() = " << sptr2.use_count() << endl;
	if (sptr1 == nullptr)
		cout << "After Move Constructor, sptr1 == nullptr" << endl;
#endif


    shared_ptr<Matrix> sptr3(new Matrix);
  
    cout << "sptr1 == sptr2 is " << (sptr1 == sptr2) << endl;
    cout << "sptr1 == sptr3 is " << (sptr1 == sptr3) << endl;


	shared_ptr<Matrix> sptr4;

	//sptr4 = sptr1; // Copy Assignment operator
	sptr4 = move(sptr1); // Move Assignment operator
    cout << "After Assignment operator" << endl;
	cout << "sptr4.use_count() = " << sptr4.use_count() << endl;
	cout << "sptr1.use_count() = " << sptr1.use_count() << endl;
	cout << "sptr2.use_count() = " << sptr2.use_count() << endl;


	return 0;
}
