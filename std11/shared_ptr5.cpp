// Array of objects
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
	//shared_ptr<Matrix[]> sptr1(new Matrix[3]);
	//shared_ptr<Matrix[3]> sptr1(new Matrix[3]);
  Matrix def;
	//shared_ptr<Matrix[]> sptr1 = make_shared<Matrix[]>(3);
	//shared_ptr<Matrix[3]> sptr1 = make_shared<Matrix[3]>();
	shared_ptr<Matrix[3]> sptr1 = make_shared<Matrix[3]>(def);

	cout << "sptr1.use_count() = " << sptr1.use_count() << endl;

	sptr1[2].display();

	return 0;
}
