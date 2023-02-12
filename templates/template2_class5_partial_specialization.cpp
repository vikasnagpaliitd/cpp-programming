// Demonstrates: Partial speciailization
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

int main()
{
	MyClass<int, string> m1(10,"world");
	MyClass<string, int> m2("hello", 999);
	MyClass<string, string> m3("hello", "world");
	//MyClass<int, int> m1(10,20); // Ques: why this line gives a compile error?

	return 0;
}
