// Copyright: Vikas Nagpal (Anuttara Learning)
// Normal iterators
#include <iostream>
#include <vector>
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
	vector<int> v1 = {1,2,3,4,5,6,7,8};

	print(v1);
	vector<int>::iterator begin = v1.begin();
	vector<int>::iterator end = v1.end();
	vector<int>::iterator i;
	for (i = begin; i!= end; i++)
		(*i) += 10;
	cout << "After adding 10 to elements throgh normal iterators" << endl;
	print(v1);


	auto iter = v1.begin();
	cout << "*iter = " << *iter << endl;
	cout << "iter[2] = " << iter[2] << endl; // Random Access iterator

	return 0;
}
