// Reverse iterators
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

	cout << "Traversing in reverse direction" << endl;
	vector<int>::reverse_iterator rbegin = v1.rbegin();
	vector<int>::reverse_iterator rend = v1.rend();
	vector<int>::reverse_iterator i;
	for (i = rbegin; i!= rend; i++)
	{
		cout << (*i) << " ";
		(*i) += 10;
	}
	cout << endl;
	cout << "After traversing in reverse direction and adding 10" << endl;
	print(v1);

	return 0;
}
