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
	list<int> l1 = {10,20,30,40,60};
	list<int> l2 = {51,52,53,54,55};

	cout << "l1 : " << endl;
	print(l1);
	cout << "l2 : " << endl;
	print(l2);


	auto iter = l1.begin();
	advance(iter, 2);
	cout <<"*iter = " << *iter << endl;
#if 1
	l1.splice(iter, l2);
#endif

#if 0
	auto iter2=find(l2.begin(), l2.end(), 52);
	l1.splice(iter, l2, iter2); // Note: should check wehther iter2 is valid or not
#endif

#if 0
	auto iter21=find(l2.begin(), l2.end(), 52);
	auto iter22=find(l2.begin(), l2.end(), 54);
	l1.splice(iter, l2, iter21, iter22); // Note: should check wehther iter2 is valid or not
#endif

	cout << endl << "After splice: " << endl;
	cout << "l1 : " << endl;
	print(l1);
	cout << "l2 : " << endl;
	print(l2);

	return 0;
}
