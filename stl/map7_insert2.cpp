// Copyright: Vikas Nagpal (Anuttara Learning)
// Demo : insert() : overload 6
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
	map<string, int> m1 { {"aaa", 1}, {"ddd", 4}, {"bbb", 2}, {"ccc", 3},  };

	print("m1", m1);

	// Overload 6
	{
		auto hint = m1.find("bbb");
		auto it = m1.insert(hint, {"abc", 90}); 
		cout << "insert at pos of 'aaa' (abc,90).\n Return: it->first = " << it->first << ", it->second = " << it->second << endl;
		print("m1", m1);
	}

	// Overload 6 : when item already exists
	{
		auto hint = m1.find("bbb");
		auto it = m1.insert(hint, {"abc", 200}); // Returns iterator to element which prevented insert
		cout << "insert at pos of 'aaa' (abc,200).\n Return: it->first = " << it->first << ", it->second = " << it->second << endl;
		print("m1", m1);
	}

	return 0;
}
