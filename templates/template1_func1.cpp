// Copyright: Vikas Nagpal (Anuttara Learning)
#include <iostream>
using namespace std;


//template <class T>
template <typename T>
T func_max(T a, T b)
{
	return ((a > b) ? a : b);
}


int main()
{
	string str1("hello"), str2("world");

	cout << "func_max(10,20) = " << func_max(10,20) << endl;
	cout << "func_max(10.1,10.2) = " << func_max(10.1,10.2) << endl;
	cout << "func_max("<< str1 << "," << str2 << ") = " << func_max(str1,str2) << endl;

	// Ques: if I wish to pass class XYZ to func_max(), which all operations should class XYZ support?

    // An explicit way to denote which instance of func_max is used
	cout << "func_max<int>(10,20) = " << func_max<int>(10,20) << endl;

	return 0;
}
