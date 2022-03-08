// Copyright: Vikas Nagpal (Anuttara Learning)
// Demo : try_try_emplace()
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
		auto [it, status] = m1.try_emplace("abc", 99);
		cout << "After try_emplace(abc,99)..." << endl;
		print_it_status(it, status);
		print("m1", m1);
	}

	{
		auto it = m1.try_emplace(m1.end(), "zbc", 1000);
		cout << "After try_emplace(zbc,1000)..." << endl;
		print_it(it);
		print("m1", m1);
	}

	return 0;
}
