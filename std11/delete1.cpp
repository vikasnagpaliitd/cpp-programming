#include <iostream>
using namespace std;


struct Foo
{
	Foo(int n):val(n) // add 'explcit' if you want it to be not used as conversion ctor
	{
		cout << "Foo(int) called" << endl;
	}
	Foo() = delete;
	Foo(const Foo& other) = delete;
	Foo(Foo&& other) = delete;
	Foo& operator=(const Foo& other) = delete;
	Foo& operator=(const Foo&& other) = delete;
	~Foo() = delete;

	int val;
};


int main()
{
	//Foo obj = 5;		// Deleted Move constructor prohibits this;
	Foo obj(5);
	cout << "obj.val = " << obj.val << endl;

	//Foo xyz(obj)l // Deleted copy constructor prohibits this;

	Foo obj2(10);

	//obj2 = obj;//error: use of deleted function ‘Foo& Foo::operator=(const Foo&)'
	//obj2 = move(obj);//error: use of deleted function ‘Foo& Foo::operator=(const Foo&&)’

	return 0;
}


