#include <iostream>
#include <sstream>
using namespace std;


// num indicates number of times, the two arguments are concatenated.
template <class T, class U, int num>
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
	cout << "func_concat<int, const char*, 5> "<< 333 << "," << "nice" << ") = " << func_concat<int, const char*, 5>(333,"nice") << endl;

	// Study the compilation error in below line
	//cout << "func_concat(10.1,10.2) = " << func_concat(10.1,10.2) << endl;
	return 0;
}
