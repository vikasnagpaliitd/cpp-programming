// Basics. use_count. expired. No -> . No *
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


	shared_ptr<Matrix> sptr1 = make_shared<Matrix>(6,6);
	weak_ptr<Matrix> wptr1(sptr1);

	shared_ptr<Matrix> ret_sptr;	
	ret_sptr = wptr1.lock(); // Gain access to managed object
	if(ret_sptr) // Should check. object may or may not be alive at time of call of lock()
	{
		cout<< "ret_sptr->x == " << ret_sptr->x << endl;
		cout<< "ret_sptr.use_count() == " << ret_sptr.use_count() << endl;
	}	

	return 0;
}
