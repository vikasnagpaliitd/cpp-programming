// Copyright: Vikas Nagpal (Anuttara Learning)
// Demo : empty(), size(), max_size()
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
	map<string, int> m1;

    cout << "m1.empty() = " << m1.empty() << endl;
    cout << "m1.size() = " << m1.size() << endl;
    cout << "m1.max_size() = " << m1.max_size() << endl;

    cout << "after adding 4 entries..." << endl;

	m1["Abc2"] = 2;
	m1["Abc1"] = 1;
	m1["Abc9"] = 9;
	m1["Abc3"] = 3;

    cout << "m1.empty() = " << m1.empty() << endl;
    cout << "m1.size() = " << m1.size() << endl;
    cout << "m1.max_size() = " << m1.max_size() << endl;

	return 0;
}
