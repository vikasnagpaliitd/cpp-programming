#include <iostream>
using namespace std;


struct Foo
{
	Foo(int n):val(n)
	{
		cout << "Foo(int) called" << endl;
	}
	//Foo() = delete;
	Foo() = default;

	//Foo(const Foo& other) = delete;
	Foo(const Foo& other) = default;

	//Foo(Foo&& other) = delete;
	Foo(Foo&& other) = default;

	//Foo& operator=(const Foo& other) = delete;
	Foo& operator=(const Foo& other) = default;

	//Foo& operator=(Foo&& other) = delete;
	Foo& operator=(Foo&& other) = default;

	//~Foo() = delete;
	~Foo() = default;

	int val;
};


int main()
{
	Foo obj1 = 5;
	Foo obj(5);
	cout << "obj.val = " << obj.val << endl;

	Foo xyz(obj);

	Foo obj2(10);
  Foo obj3;

	//obj2 = obj;
	obj2 = move(obj);//error: use of deleted function ‘Foo& Foo::operator=(const Foo&&)’

  Foo obj4(move(obj));
	return 0;
}


