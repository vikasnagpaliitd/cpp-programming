#include <iostream>
#include <list>
using namespace std;

int main()
{
	list<int> l1;
	//list<int> l1 = {3,4,5};
	//list<int> l1(5,3);

	// Can push/pop to/from both ends (in constant time)
	l1.push_back(99);
	l1.push_front(2);
	l1.push_back(100);
	l1.push_front(1);


	for(list<int>::iterator i = l1.begin(); i != l1.end(); i++)
		cout << *i << endl;

	list<int> l2(l1.begin(), l1.end());
	cout << "l2 list:" << endl;
#if 0
	for(list<int>::iterator i = l1.begin(); i != l1.end(); i++)
		cout << *i << endl;
#endif
  //for(auto item:l2)
  //for(auto& item:l2)
  for(const auto& item:l2)
  {
		cout << item << endl;
    item+=1000;
  }
	cout << "l2 list (after incr by 1000):" << endl;
  for(auto item:l2)
		cout << item << endl;

	return 0;
}
