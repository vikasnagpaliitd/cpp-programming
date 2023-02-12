//Demonstrates : Multiple inheritance from two base classses having same named functions/data
#include <iostream>
using namespace std;

class Base1
{
	public:
	    int data;

        int getData()
		{
			cout << "Base1::getData() called" << endl;
			return data;
		}

	    Base1(int value) : data(value)
		{
		}
};

class Base2
{
	public:
	    int data;

        int getData()
		{
			cout << "Base2::getData() called" << endl;
			return data;
		}

	    Base2(int value) : data(value)
		{
		}
};


class Derived : public Base1, public Base2
{

	public:
		Derived(int data1, int data2) : Base1(data1), Base2(data2)
		{
		}
};


int main()
{
    Derived d(5,10);

    //cout << "d.data = " << d.data << endl; // error: request for member ‘data’ is ambiguous
    cout << "d.Base1::data = " << d.Base1::data << endl;
    cout << "d.Base2::data = " << d.Base2::data << endl;
    cout << d.Base1::getData() << endl;
    cout << d.Base2::getData() << endl;
	return 0;
}

