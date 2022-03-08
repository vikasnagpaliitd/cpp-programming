// Copyright: Vikas Nagpal (Anuttara Learning)
// Demo : clear()
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

	m1["Abc2"] = 2;
	m1["Abc1"] = 1;
	m1["Abc9"] = 9;
	m1["Abc3"] = 3;

	print("m1", m1);
    cout << "m1.size() = " << m1.size() << endl;

    m1.clear();
	cout << "After clear() ..." << endl;

	print("m1", m1);
    cout << "m1.size() = " << m1.size() << endl;

	return 0;
}
