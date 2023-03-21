#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void my_print(int x)
{
	cout << x << endl;
}

int main()
{
	vector<int> v1;

	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);

	for_each(v1.begin(), v1.end(), [](auto& x) { x *= 2; x*= 3;}); // multiply by 6 // returns void by default
	for_each(v1.begin(), v1.end(), my_print);

  auto check_func = [](int elem)-> bool { cout<< "inside check_func"<< endl; return elem > 100;}; // returns bool
  //auto check_func = []<typename T>(T elem)-> bool { cout<< "inside check_func"<< endl; return elem > 100;}; // templated lambdas since C++20
  auto ret= count_if(v1.begin(), v1.end(), check_func);
	cout << "count_if returned "<< ret << endl;


	return 0;
}
