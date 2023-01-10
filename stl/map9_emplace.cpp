// Demo : emplace() // like insert and not insert_or_assign
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
		auto [it, status] = m1.emplace("abc", 99);
		cout << "After emplace(abc,99)..." << endl;
		print_it_status(it, status);
		print("m1", m1);
	}

	{
		auto [it, status] = m1.emplace("abc", 1000);
		cout << "After emplace(abc,1000)..." << endl;
		print_it_status(it, status);
		print("m1", m1);
	}

	// More ways to call emplace
	{
		auto [it, status] = m1.emplace(make_pair("ff1", 200)); // pair
		auto [it1, status1] = m1.emplace(piecewise_construct, forward_as_tuple(5,'g'), forward_as_tuple(10)); //piecewise calling constructors
		cout << "After emplace ff1 and ggggg..." << endl;
		//print_it_status(it, status);
		print("m1", m1);
	}

	return 0;
}
