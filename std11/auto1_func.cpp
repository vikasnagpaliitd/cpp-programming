#include <iostream>
using namespace std;

//auto add(auto x, auto y) -> decltype(x+y)
auto add(auto x, auto& y)
{
  y++;
	return x + y;
}

int main()
{
  int a=10, b=20; 
	auto ret_int = add(1,a);
	//auto ret_double = add(1.0,2.0); // by default, double literals
	//auto ret_float = add(1.0f,2.0f); // float literals
	cout << "sizeof(float) = " << sizeof(float) << endl;
	cout << "sizeof(double) = " << sizeof(double) << endl;
	//cout << "sizeof(ret_double) = " << sizeof(ret_double) << endl;
	//cout << "sizeof(ret_float) = " << sizeof(ret_float) << endl;

	cout << "ret_int = " << ret_int << endl;
	//cout << "ret_double = " << ret_double << endl;
	//cout << "ret_float = " << ret_float << endl;
  cout << "a = " << a << endl;

	return 0;
}
