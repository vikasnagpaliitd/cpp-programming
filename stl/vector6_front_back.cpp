// Copyright: Vikas Nagpal (Anuttara Learning)
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v1;

	cout << "Push 10..." << endl;
	v1.push_back(10);
	cout << "Push 20..." << endl;
	v1.push_back(20);
	cout << "Push 30..." << endl;
	v1.push_back(30);

	cout << "v1.front() = " << v1.front() << endl;
	cout << "v1.back() = " << v1.back() << endl;


	return 0;
}
