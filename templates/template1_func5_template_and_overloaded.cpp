// Copyright: Vikas Nagpal (Anuttara Learning)
#include <iostream>
#include <cstring>
using namespace std;


//template <class T>
template <typename T>
T func_max(T a, T b)
{
	return ((a > b) ? a : b);
}


// Note: we can have specialized implementation also
//template <>
//char *func_max<char*>(char *a, char *b)
//  OR
//Overloaded function for specific value of T
char *func_max(char *a, char *b)
{
	//cout << "Debug: specialized function for char*" << endl;
	return ((strcmp(a,b) > 0) ? a : b);
}


int main()
{
	string str1("hello"), str2("world");
	char arr1[]="hello";
	char arr2[]="world";

	cout << "func_max(10,20) = " << func_max(10,20) << endl;
	cout << "string:func_max("<< str1 << "," << str2 << ") = " << func_max(str1,str2) << endl;
	cout << "char array:func_max("<< arr1 << "," << arr2 << ") = " << func_max(arr1,arr2) << endl;
	return 0;
}
