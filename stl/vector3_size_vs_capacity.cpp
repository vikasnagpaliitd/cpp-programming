// Copyright: Vikas Nagpal (Anuttara Learning)
#include <iostream>
#include <vector>
using namespace std;


int main()
{
	vector<int> v1;

	cout << "v1.size() = " << v1.size() << endl;
	cout << "v1.capacity() = " << v1.capacity() << endl;


	for(int i = 0; i < 10; i++)
	{
		v1.push_back(10 + i);
		cout << "v1.size() = " << v1.size() << endl;
		cout << "v1.capacity() = " << v1.capacity() << endl;
	}


	return 0;
}
