// Copyright: Vikas Nagpal (Anuttara Learning)
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

template <typename T>
void print(const T& cnt)
{
	cout << "[ ";
	for (const auto& i : cnt)
		cout << i << " ";
	cout << " ]" << endl;
}

bool check_range(int n)
{
	return ((n >=10) && (n<=20));
}

int main()
{
	list<int> l1 = {10,20,10,30,10,40,60};

	cout << "l1 : " << endl;
	print(l1);


#if 1
	l1.remove(10);
#endif

#if 0
	l1.remove_if(check_range);// function
	//l1.remove_if([](int n){return ((n >=10) && (n<=20));}); // Lambda functions
	//Note: we could pass a functor object too
#endif


	cout <<  "After remove(): " << endl;
	cout << "l1 : " << endl;
	print(l1);

	return 0;
}
