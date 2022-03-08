// Copyright: Vikas Nagpal (Anuttara Learning)
//Demonstrates : Hybrid inherit. Common base class. diamond problem. Virtual base class solution
#include <iostream>
using namespace std;

class Base
{
	public:
	    int data;

	    Base(int value) : data(value)
		{
			cout << "Base(int) constructor" << endl;
		}
};

class Child1 : virtual public Base
{
	public:
		Child1(int val): Base(val)
        {
			cout << "Child1(int) constructor" << endl;
        }
};

class Child2 : virtual public Base
{
	public:
		Child2(int val): Base(val)
        {
			cout << "Child2(int) constructor" << endl;
        }
};

class GrandChild: public Child1, public Child2
{
	public:
		GrandChild(int val1, int val2) : Base(1), Child1(val1), Child2(val2)
		{
			cout << "GrandChild(int) constructor" << endl;
		}
};


int main()
{
    GrandChild obj(5,10);

    cout << "obj.data = " << obj.data << endl;
    cout << "obj.Base::data = " << obj.Base::data << endl;
    cout << "obj.Child1::Base::data = " << obj.Child1::Base::data << endl;

    cout << "obj.Child1::data = " << obj.Child1::data << endl;
    cout << "obj.Child2::data = " << obj.Child2::data << endl;
	return 0;
}

