#include <iostream>
#include <list>
#include <algorithm>
#include <functional>
using namespace std;

template <typename T>
void print(const T& cnt)
{
	cout << "[ ";
	for (const auto& i : cnt)
		cout << i << " ";
	cout << " ]" << endl;
}

int main()
{
	list<int> l1 = {10,20,10,-1,10,40,60};

	cout << "l1 : " << endl;
	print(l1);


	l1.sort();
	cout <<  "After sort(): " << endl;
	cout << "l1 : " << endl;
	print(l1);

	l1.sort(greater<int>());
	cout <<  "After sort() with greater<int>(): " << endl;
	cout << "l1 : " << endl;
	print(l1);

	return 0;
}
