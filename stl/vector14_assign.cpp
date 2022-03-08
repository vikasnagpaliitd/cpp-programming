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

	vector<int> v2 = {4,5,6,7,8,9};

	v1.assign(3,22); // 3 times 22	
	//v1.assign({1,3,5,7,9}); 
	//v1.assign(v2.begin()+1, v2.end() -2);

	cout << "after v1.assign()" << endl;
	print(v1);


	return 0;
}
