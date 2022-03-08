// Copyright: Vikas Nagpal (Anuttara Learning)
// Const iterators
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
	vector<int>::const_iterator cbegin = v1.cbegin();
	vector<int>::const_iterator cend = v1.cend();
	vector<int>::const_iterator i;
	for (i = cbegin; i!= cend; i++)
	{
		//(*i) += 10; // does not compile
		cout << *i << " ";
	}
	cout << endl;

	return 0;
}
