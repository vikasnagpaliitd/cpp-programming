// Copyright: Vikas Nagpal (Anuttara Learning)
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
	vector<int> v1;

	v1.push_back(10);
	v1.push_back(20);
	cout << "Push 30..." << endl;
	v1.push_back(30);
	cout << "After push 10, 20, 30..." << endl;
	print(v1);

	auto iter = v1.begin();
	v1.insert(iter, 5);
	cout << "After intert 5 at v1.begin()..." << endl;
	print(v1);

	iter = v1.begin();
	v1.insert(iter, 3,2);
	cout << "After intert 3,2 at v1.begin()..." << endl;
	print(v1);

	vector<int> v2 {-1,-2,-3};

	iter = v1.begin() + 1; // Notice: + 1
	v1.insert(iter, v2.begin(), v2.end());
	cout << "After intert -1,-2,-3 at begin+1" << endl;
	print(v1);

	v1.insert(v1.end() - 2, {99,88,77}); //initializer-list
	cout << "After intert 99,88,77 at end-2" << endl;
	print(v1);

	auto iter1 = find(v1.begin(), v1.end(), 77); // its  a generic algorithm // returns last if not found
	if (iter1 != v1.end())
	{
		v1.insert(iter1, {-6,-5}); 
		cout << "After intert -6,-5 before 77" << endl;
		print(v1);
	}

	return 0;
}
