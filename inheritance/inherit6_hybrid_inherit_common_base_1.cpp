//Demonstrates : Hybrid inherit. Common base class. diamond problem
/* Inheritance Hierarchy
   - Base
   - Child1 derives from Base
   - Child2 derives from Base
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
			cout << "Base(int) Constructor" << endl;
		}
};

class Child1 : public Base
{
	public:
		Child1(int val): Base(val)
        {
			cout << "Child1(int) Constructor" << endl;
        }
};

class Child2 : public Base
{
	public:
		Child2(int val): Base(val)
        {
			cout << "Child2(int) Constructor" << endl;
        }
};

class GrandChild: public Child1, public Child2
{
	public:
        // Ques: should constructor take two int(s) or one int?
		GrandChild(int val1, int val2) : Child1(val1), Child2(val2)
		{
			cout << "GrandChild(int) Constructor" << endl;
		}
};

int main()
{
    GrandChild obj(5,10);

    //cout << "obj.Base::data = " << obj.Base::data << endl;// error: ‘Base’ is an ambiguous base of ‘GrandChild’

    cout << "obj.Child1::data = " << obj.Child1::data << endl; // 5
    cout << "obj.Child2::data = " << obj.Child2::data << endl; // 10

    // Note: Base constructor is called twice. Implies two instances of Base within GrandChild!

	return 0;
}

