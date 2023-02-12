// Demonstrates: template function as a generic type based code
#include <iostream>
#include <typeinfo>
using namespace std;

//template <class T>
template <typename T>
T func_max(T a, T b)
{
	cout << "func_max with " << typeid(a).name() <<  endl;
	return ((a > b) ? a : b);
}

int main()
{
	string str1("hello"), str2("world");

	cout << "func_max(10,20) = " << func_max(10,20) << endl;
	cout << "func_max(10.1,10.2) = " << func_max(10.1,10.2) << endl;
	cout << "func_max("<< str1 << "," << str2 << ") = " << func_max(str1,str2) << endl;
	cout << "func_max(1.1f,1.2f) = " << func_max(1.1f,1.2f) << endl;
	cout << "func_max(abc, def) = " << func_max("hello", "world") << endl;
	// Ques: if I wish to pass class XYZ to func_max(), which all operations should class XYZ support?

    // An explicit way to denote which instance of func_max is used
	cout << "func_max<int>(10,20) = " << func_max<int>(10,20) << endl;
	cout << "func_max<int>(10.1,20.2) = " << func_max<int>(10.1,20.2) << endl;
	return 0;
}
