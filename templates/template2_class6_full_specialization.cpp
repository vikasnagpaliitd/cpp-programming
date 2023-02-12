// Demonstrates: Full speciailization
#include <iostream>
using namespace std;

template <class X, class Y>
class MyClass
{
	public:

	MyClass(X x, Y y)
	{
		cout << "MyClass: x = " << x << ", y = " << y << endl;
	}
};

// Specialize for cases when first argument is int
template <class Y>
class MyClass<int, Y>
{
	public:

	MyClass(int x, Y y)
	{
		cout << "FirstSpecialized MyClass<int, Y>: x = " << x << ", y = " << y << endl;
	}
};

// Specialize for cases when second argument is int
template <class X>
class MyClass<X, int>
{
	public:

	MyClass(X x, int y)
	{
		cout << "SecondSpecialized MyClass<X, int>: x = " << x << ", y = " << y << endl;
	}
};

//Full specialization
template <>
class MyClass<string, string>
{
	public:

	MyClass(string x, string y)
	{
		cout << "StringFullSpecializedMyClass: x = " << x << ", y = " << y << endl;
	}
};

//Full specialization
template <>
class MyClass<int, int>
{
	public:

	MyClass(int x, int y)
	{
		cout << "intFullSpecializedMyClass: x = " << x << ", y = " << y << endl;
	}
};

int main()
{
	MyClass<int, string> m1(10,"world");
	MyClass<string, int> m2("hello", 999);
	MyClass<string, string> m3("hello", "world");
	MyClass<bool, bool> m4(true, false);
	MyClass<int, int> m5(100,200);

	return 0;
}
