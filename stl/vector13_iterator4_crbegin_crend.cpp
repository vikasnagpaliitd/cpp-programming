// Const Reverse iterators
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
	vector<int>::const_reverse_iterator crbegin = v1.crbegin();
	vector<int>::const_reverse_iterator crend = v1.crend();
	vector<int>::const_reverse_iterator i;
	for (i = crbegin; i!= crend; i++)
	{
		//(*i) += 10; // does not compile
		cout << *i << " ";
	}
	cout << endl;

	return 0;
}
