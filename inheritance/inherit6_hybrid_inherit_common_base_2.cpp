//Demonstrates : Hybrid inherit. Common base class. Solution of Diamond problem
//   Solution : use Virtual base class
/* Inheritance Hierarchy
   - Base
   - Child1 derives from Base (virtual inheritance)
   - Child2 derives from Base (virtual inheritance)
   - GrandChild derives from Child1 and Child2
*/
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

class Child1 : virtual public Base // Note: virtual inheritance
{
	public:
		Child1(int val): Base(val)
        {
			cout << "Child1(int) constructor" << endl;
        }
};

class Child2 : virtual public Base // Note: virtual inheritance
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
		//GrandChild(int val) : Base(val), Child1(val), Child2(val) 
		{
			cout << "GrandChild(int) constructor" << endl;
		}
};

int main()
{
    GrandChild obj(5,10);
    //GrandChild obj(15);

    cout << "obj.data = " << obj.data << endl;
    cout << "obj.Base::data = " << obj.Base::data << endl;
    cout << "obj.Child1::Base::data = " << obj.Child1::Base::data << endl;

    cout << "obj.Child1::data = " << obj.Child1::data << endl;
    cout << "obj.Child2::data = " << obj.Child2::data << endl;
	return 0;
}

