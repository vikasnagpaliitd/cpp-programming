// Demonstrates: multiple similar function different in type of arguments
#include <iostream>
using namespace std;

int func_max(int a, int b)
{
	cout << "func_max with int" << endl;
	return ((a > b) ? a : b);
}

double func_max(double a, double b)
{
	cout << "func_max with double" << endl;
	return ((a > b) ? a : b);
}

string func_max(string a, string b)
{
	cout << "func_max with string" << endl;
	return ((a > b) ? a : b);
}


int main()
{
	string str1("hello"), str2("world");

	cout << "func_max(10,20) = " << func_max(10,20) << endl;
	cout << "func_max(10.1,10.2) = " << func_max(10.1,10.2) << endl;
	cout << "func_max("<< str1 << "," << str2 << ") = " << func_max(str1,str2) << endl;

	// Ques: which function shall get called?
	cout << "func_max(1.1f,1.2f) = " << func_max(1.1f,1.2f) << endl;
	return 0;
}
