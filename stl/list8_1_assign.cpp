#include <iostream>
#include <vector>
#include <list>
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
	vector<int> v1({10,20,30,40,50});

	list<int> l1 = {4,5,6,7,8,9};

	//l1.assign(3,22); // 3 times 22	
	//l1.assign({1,3,5,7,9}); 
	l1.assign(v1.begin()+1, v1.end() -2);

	cout << "after l1.assign()" << endl;
	print(l1);


	return 0;
}
