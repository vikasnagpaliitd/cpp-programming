#include <iostream>
#include <vector>
using namespace std;


int main()
{
	vector<int> v1;

    cout << "v1.empty() = " << v1.empty() << endl;
	cout << "Pushing 10..." << endl;

	v1.push_back(10);

    cout << "v1.empty() = " << v1.empty() << endl;
    cout << "v1.size() = " << v1.size() << endl;
    cout << "v1.capacity() = " << v1.capacity() << endl;

	cout << "v1. reserve(11).." << endl;
	v1.reserve(11);
    cout << "v1.size() = " << v1.size() << endl;
    cout << "v1.capacity() = " << v1.capacity() << endl;

	return 0;
}
