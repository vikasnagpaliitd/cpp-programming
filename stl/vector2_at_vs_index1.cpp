// Copyright: Vikas Nagpal (Anuttara Learning)
#include <iostream>
#include <vector>
using namespace std;


int main()
{
	vector<int> v1;

	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);

	cout << "v1[3] = " << v1[3] << endl; // undefined behavior


	cout << "v1.at(3) = " << v1.at(3) << endl; // throws exception std::out_of_range


	return 0;
}
