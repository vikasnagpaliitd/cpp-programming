#include <iostream>
#include <vector>
using namespace std;


int main()
{
	vector<int> v1;

	for(int i = 0; i < 100; i++)
		v1.push_back(i);

	cout << "After pushing 100 elements" << endl;
	cout << "v1.size() = " << v1.size() << endl;
	cout << "v1.capacity() = " << v1.capacity() << endl;

	for(int i = 0; i < 90; i++)
		v1.pop_back();

	cout << "After popping 90 elements" << endl;
	cout << "v1.size() = " << v1.size() << endl;
	cout << "v1.capacity() = " << v1.capacity() << endl;

	v1.shrink_to_fit();

	cout << "After v1.shrink_to_fit()" << endl;
	cout << "v1.size() = " << v1.size() << endl;
	cout << "v1.capacity() = " << v1.capacity() << endl;

	return 0;
}
