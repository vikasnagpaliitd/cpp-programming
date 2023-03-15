// Demonstrates: Full speciailization
#include <iostream>
using namespace std;

template <class X>
class MyClass
{
	public:

	MyClass(X x)
	{
		cout << "MyClass: x = " << x << endl;
	}
};

//specialization for array
template <class X>
class MyClass<X[]>
{
	public:

	MyClass(X arr[])
	{
		cout << "MyClass<X[] arr>: arr[0] = " << arr[0] << endl;
	}
};

int main()
{
	MyClass<int> m1(10);
  int a[3] = {11,12,13};
  int b[5] = {110,12,13};
	//MyClass<int[3]> m2({11,12,13});
	MyClass<int[]> m2(a);
	MyClass<int[]> m3(b);

	return 0;
}
