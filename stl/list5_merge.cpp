#include <iostream>
#include <list>
#include <algorithm>
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
	list<int> l1 = {10,20,30,40,50};
	list<int> l2 = {11,21,35,43,59, 90,100};

	cout << "l1 : " << endl;
	print(l1);
	cout << "l2 : " << endl;
	print(l2);


	l1.merge(l2);

	cout << endl << "After merging : " << endl;
	cout << "l1 : " << endl;
	print(l1);
	cout << "l2 : " << endl;
	print(l2);

	return 0;
}
