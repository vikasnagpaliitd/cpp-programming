// Basics of weak_ptr. use_count. expired. No -> or *
#include <iostream>
#include <memory>
using namespace std;

class Matrix
{
	public:
	int x,y;

	Matrix(int rows=5, int cols=5) { x=rows;y=cols;cout << "Constructor:Matrix" << endl; }
	Matrix(const Matrix& other) { cout << "Copy Constructor:Matrix" << endl; }
	~Matrix() { cout << "Destructor:Matrix" << endl; }
	void display() { cout << "display():Matrix" << endl; }

};

int main()
{

	weak_ptr<Matrix> wptr1;

	cout << "Outside: wptr1.use_count() = " << wptr1.use_count() << endl;
	cout << "Outside: wptr1.expired() = " << boolalpha << wptr1.expired() << endl;
	{
	    shared_ptr<Matrix> sptr1 = make_shared<Matrix>(6,6);
		shared_ptr<Matrix> sptr2(sptr1); // just to increase ref count
		wptr1 = sptr1;

		cout << "\tInside: wptr1.use_count() = " << wptr1.use_count() << endl;
		cout << "\tInside: wptr1.expired() = " << boolalpha << wptr1.expired() << endl;

	}

	cout << "Outside: wptr1.use_count() = " << wptr1.use_count() << endl;
	cout << "Outside: wptr1.expired() = " << boolalpha << wptr1.expired() << endl;

    //wptr1->display(); // does not compile
    //*wptr1; // does not compile

	return 0;
}
