// Copyright: Vikas Nagpal (Anuttara Learning)
// explcit keyword
#include <iostream>
using namespace std;


struct Foo
{
	explicit Foo(int n):val(n) // add 'explcit' if you want it to be not used as conversion ctor
	{
		cout << "Foo(int) called" << endl;
	}

	//operator int()
	explicit operator int()
	{
		cout << "operator int() called" << endl;
		return val*100;
	}
	int val;
};


Foo create()
{
	return (Foo) 5;	// Notice type casting style syntax
}

int main()
{
	Foo obj = Foo(5);
	int x;

	obj = create();

	cout << "obj.val = " << obj.val << endl;

	//x = (int)obj;
	x = int(obj);
	cout << "x = " << x << endl;

	return 0;
}


