#include <iostream>
using namespace std;


struct Foo
{
	Foo(int n):val(n) // add 'explcit' if not intended to be implicitly used
	//explicit Foo(int n):val(n) 
	{
		cout << "Foo(int) called" << endl;
	}
	int val;
};


Foo create()
{
	return 5;	// Works if implicit conversion ctor
		   // Compiler replaces the call with return Foo(5)

	//return Foo(5);	// Works even if 'explicit' ctor 
}

int main()
{
	Foo obj = 5;		// Works if implicit conversion ctor
	//Foo obj(5);		// Works even if 'explicit' ctor

	obj = create();

	cout << "obj.val = " << obj.val << endl;

	return 0;
}

