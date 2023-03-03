// Demo : emplace_hint()
#include <iostream>
#include <map>
using namespace std;

template <class M>
void print(string name, const M &m)
{
	cout << name << endl;
	for (auto i : m)
		cout << i.first << " " << i.second << endl;
	cout << endl;
}
void print_it_status(auto it, bool status) // notice auto here
{
	cout << "it->first = " << it->first << ", it->second = " << it->second << ", status = " << status << endl;
}
void print_it(auto it) // notice auto here
{
	cout << "it->first = " << it->first << ", it->second = " << it->second << endl;
}

int main()
{
	map<string, int> m1{
		{"aaa", 1},
		{"ddd", 4},
		{"bbb", 2},
		{"ccc", 3},
	};

	print("m1", m1);

	{
		m1.emplace_hint(m1.end(), "eee", 99);
		m1.emplace_hint(m1.end(), "fff", 99);
		m1.emplace_hint(m1.end(), "ggg", 99);
		m1.emplace_hint(m1.end(), "hhh", 99);
		cout << "After emplace eee , ffff, ggg, hhh..." << endl;
		print("m1", m1);
	}

	// More ways to call emplace
	{
		m1.emplace_hint(m1.end(), piecewise_construct, forward_as_tuple(5,'j'), forward_as_tuple(10)); //piecewise calling constructors
		cout << "After emplace jjjjj..." << endl;
		print("m1", m1);
	}

	return 0;
}
