//Conversion ctor can have other args having default values
// After std11, conversion constructor can also convert from initializer list
#include <iostream>
using namespace std;


struct Foo
{
	Foo(int n, float f=2.3, char c='r'):val(n)
	{
		cout << "Foo(int) called" << endl;
	}
	int val;
};


Foo create1()
{
	return 15; // Compiler replaces the call with return Foo(5, 2.3, 'r')
}

Foo create2()
{
	return {20, 1.1, 't'}; 
}

int main()
{
	Foo obj = 5;
	cout << "obj.val = " << obj.val << endl;

	obj = create1();
	cout << "obj.val = " << obj.val << endl;

	obj = create2();
	cout << "obj.val = " << obj.val << endl;

	obj = {25, 11.0, 'a'};
	cout << "obj.val = " << obj.val << endl;

	return 0;
}


