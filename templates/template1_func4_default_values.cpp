// Demonstrates: default values of type or non-type template arguments
#include <iostream>
#include <sstream>
using namespace std;

template <class T, class U=const char*, int num=5>
string func_concat(T a, U b)
{
	ostringstream s;
	for(int i = 0; i < num; i++)
		s << a << b << " ";
	return string(s.str());
}

int main()
{
	string str1("hello"), str2("world");

	cout << "func_concat<double, double, 1>(10.1,10.2) = " << func_concat<double, double,1>(10.1,10.2) << endl;
	cout << "func_concat<string,string,2>("<< str1 << "," << str2 << ") = " << func_concat<string, string, 2>(str1,str2) << endl;
	cout << "func_concat<string, int, 3>("<< str1 << "," << 100 << ") = " << func_concat<string, int, 3>(str1,100) << endl;
	cout << "func_concat<int, string, 4>("<< 999 << "," << str2 << ") = " << func_concat<int, string, 4>(999,str2) << endl;
	cout << "func_concat<int, const char*, 2> "<< 333 << "," << "nice" << ") = " << func_concat<int, const char*, 2>(333,"nice") << endl;
	// Default num
	cout << "func_concat<int, const char*> "<< 333 << "," << "nice" << ") = " << func_concat<int, const char*>(333,"nice") << endl;
	// Default U and num
	cout << "func_concat<int> "<< 222 << "," << "good" << ") = " << func_concat<int>(222,"good") << endl;

	// Compiler Auto derived template paramters
	cout << "func_concat(101,102) = " << func_concat(101,102) << endl;
	return 0;
}
