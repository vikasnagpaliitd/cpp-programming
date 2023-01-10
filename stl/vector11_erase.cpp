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

	v1.erase(v1.begin());
	cout << "After erase v1.begin()" << endl;
	print(v1);

	v1.erase(v1.begin() + 2, v1.end() - 2);
	cout << "After erase v1.begin()+2, v1.end()-2" << endl;
	print(v1);

	return 0;
}
