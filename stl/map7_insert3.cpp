// Copyright: Vikas Nagpal (Anuttara Learning)
// Demo : insert() : overload 7 and 8
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
	map<string, int> m2 = {{ "eee", 5}};

	print("m2", m2);

	m2.insert(m1.begin(), m1.end()); // Overload 7 : range
	cout << "After insert..." << endl;
	print("m2", m2);

	m2.insert({{"kkk", 90}, {"iii", 89}}); // Overload 8 : initializer list
	cout << "After insert:{'kkk', 90}, {'iii', 89}}..." << endl;
	print("m2", m2);

	return 0;
}
