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

	cout << "v1[0] = " << v1[0] << endl;
	cout << "v1[1] = " << v1[1] << endl;
	cout << "v1[2] = " << v1[2] << endl;


	cout << "v1.at(0) = " << v1.at(0) << endl;
	cout << "v1.at(1) = " << v1.at(1) << endl;
	cout << "v1.at(2) = " << v1.at(2) << endl;


	return 0;
}
