// Copyright: Vikas Nagpal (Anuttara Learning)
#include <iostream>
using namespace std;


struct Foo
{
	Foo(int n):val(n) // add 'explcit' if you want it to be not used as conversion ctor
	{
		cout << "Foo(int) called" << endl;
	}
	int val;
};


Foo create()
{
	return 5;	// Conversion constructor invoked. 
		   // Compiler replaces the call with return Foo(5)
}

int main()
{
	Foo obj = 5;		// perfectly valid, compiles fine

	obj = create();

	cout << "obj.val = " << obj.val << endl;

	return 0;
}


