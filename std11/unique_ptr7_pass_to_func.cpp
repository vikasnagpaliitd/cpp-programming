// Copyright: Vikas Nagpal (Anuttara Learning)
// can we pass unique pointer to function
#include <iostream>
#include <memory>
using namespace std;

class Matrix
{
	int x,y;
	public:

	Matrix(int rows=5, int cols=5) :x(rows), y(cols) { cout << "Constructor:Matrix :" << rows << ", " << cols << endl; }
	Matrix(const Matrix& other) :x(other.x), y(other.y) { cout << "Copy Constructor:Matrix" << x << ", " << y << endl; }
	~Matrix() { cout << "Destructor:Matrix" << x << ", " << y << endl; }
	void display() { 
		cout << "display():Matrix" << x << ", " << y << endl; 
	}

};

void display(unique_ptr<Matrix> uptr)
{
  uptr->display();
}

void bad_display(unique_ptr<Matrix>& uptr) // bad practice
{
  uptr->display();
}

int main()
{

	unique_ptr<Matrix> uptr1(make_unique<Matrix>(8,8)); 


	//display(uptr1); // does not compile as copy constructor is involved
	bad_display(uptr1); // works. but bad practice. reference to pointer is non-intuitive
	display(std::move(uptr1)); // works but uptr1 becomes equivalent to nullptr



	cout << "uptr1.get() = " << uptr1.get() << endl;

	display(make_unique<Matrix>(9,9)); // works as move constructor is involved
	cout << "after return from display()" << endl;


	return 0;
}
