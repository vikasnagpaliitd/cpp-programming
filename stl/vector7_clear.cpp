// Copyright: Vikas Nagpal (Anuttara Learning)
#include <iostream>
#include <vector>
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
	vector<int> v1;

	cout << "Push 10..." << endl;
	v1.push_back(10);
	print(v1);
	cout << "Push 20..." << endl;
	v1.push_back(20);
	print(v1);
	cout << "Push 30..." << endl;
	v1.push_back(30);
	print(v1);

	

	cout << "v1.clear()" << endl;
	v1.clear();
	print(v1);
	cout << "v1.size() = " << v1.size() << endl;
	cout << "v1.capacity() = " << v1.capacity() << endl;


	return 0;
}
