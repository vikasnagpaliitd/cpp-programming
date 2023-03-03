// Demo : erase()
#include <iostream>
#include <map>
using namespace std;

template <class M>
void print(string name, const M& m)
{
	cout << name << endl;
	for(auto i:m)
		cout << i.first << " " << i.second << endl;
	cout << endl;
}

int main()
{
	map<string, int> m1 { {"aaa", 1}, {"ddd", 4}, {"bbb", 2}, {"ccc", 3}, {"eee",10}, {"fff", 11}  };
	
	print("m1", m1);
	auto it = m1.find("bbb");
	if (it != m1.end())
		m1.erase(it); // erase using iterator

	cout << "after erasing bbb..." << endl;
	print("m1", m1);

	auto first = m1.find("ccc");
	auto last = m1.find("eee");
	m1.erase(first, last); // erase using range
	cout << "after erasing [ccc, eee)..." << endl;
	print("m1", m1);


	m1.erase("fff"); // erase using key
	cout << "after erasing fff as key..." << endl;
	print("m1", m1);

	m1.erase("fff"); // erase using key
	cout << "after erasing fff again as key..." << endl;
	print("m1", m1);

	return 0;
}
