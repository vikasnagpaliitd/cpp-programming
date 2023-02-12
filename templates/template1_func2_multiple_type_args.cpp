// Demonstrates: Multiple type arguments
#include <iostream>
#include <sstream>
using namespace std;
 
// Concatenate two variables of any data types
template <class T, class U>
string func_concat(T a, U b)
{
	// ostringstream s;
	// s << a << b;
	// return string(s.str());
}

// Ques: if I wish to pass class XYZ to func_max(), which all operations should class XYZ support?

int main()
{
	string str1("hello"), str2("world");

	cout << "func_concat(10.1,10.2) = " << func_concat(10.1,10.2) << endl;
	cout << "func_concat("<< str1 << "," << str2 << ") = " << func_concat(str1,str2) << endl;
	cout << "func_concat("<< str1 << "," << 100 << ") = " << func_concat(str1,100) << endl;
	cout << "func_concat("<< 999 << "," << str2 << ") = " << func_concat(999,str2) << endl;
	cout << "func_concat("<< 333 << "," << "nice" << ") = " << func_concat(333,"nice") << endl;
	return 0;
}
