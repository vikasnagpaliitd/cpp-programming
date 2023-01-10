// Bidirectional iterator
#include <iostream>
#include <list>
using namespace std;

int main()
{
	list<int> l1 = {10,20,30,40,50};


	auto iter = l1.begin();
	cout << "value at iter = " << *iter << endl;

	iter++;
	cout << "iter++" << endl;
	cout << "value at iter = " << *iter << endl;

	iter--;
	cout << "iter--" << endl;
	cout << "value at iter = " << *iter << endl;

	//iter += 2; // does not compile
	//cout << "value at iter = " << iter[2] << endl; //does not compile

	return 0;
}
