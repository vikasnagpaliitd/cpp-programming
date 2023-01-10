#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

//Note: the below template function is same as the one which worked for vector
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
	list<int> l1 = {10,20,30,40,50};


	print(l1);
	auto iter = l1.begin();

	l1.insert(iter, 5);
	cout << "after insert(5) in beginning" << endl;
	print(l1);

	l1.insert(l1.end(), 65);
	cout << "after insert(65) in end" << endl;
	print(l1);

	iter = find(l1.begin(), l1.end(), 30);
	if (iter != l1.end())
	{
		l1.insert(iter,5,-1);
		cout << "after insert(5,-1) before 30" << endl;
		print(l1);

		list<int> l2 = {41,42,43};
		l1.insert(iter, l2.begin(), l2.end()); // insert does not invaliate iter
		cout << "after insert{41,42,43}before 30" << endl;
		print(l1);
	}


	auto iter1 = find(l1.begin(), l1.end(), 20);
	if (iter1 != l1.end())
	{
		l1.erase(iter1);
		cout << "after erase(iter of 20)" << endl;
		print(l1);


	}


	iter1 = find(l1.begin(), l1.end(), 10);
	auto iter2 = find(l1.begin(), l1.end(), 43);
	l1.erase(iter1, iter2); // ideally, should check against l1.end() to see whether we found the elements
	cout << "after erase(iter of [10,43))" << endl;
	print(l1);
	return 0;
}
