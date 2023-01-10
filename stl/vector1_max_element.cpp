#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> v1;

	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);


	cout << "Max element is : " << * max_element(v1.begin(), v1.end()) << endl;// * to dereference the iterator



	return 0;
}
