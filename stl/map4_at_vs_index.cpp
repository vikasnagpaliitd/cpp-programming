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
	//map<string, int> m1;
	map<string, int, greater<string>> m1;

	m1["Abc2"] = 2;
	m1["Abc1"] = 1;
	m1["Abc9"] = 9;
	m1["Abc3"] = 3;

	cout << "m1.at(Abc9) = " << m1.at("Abc9") << endl;
	//cout << "m1.at(Abc19) = " << m1.at("Abc19") << endl; // std::out_of_range
	cout << "m1[Abc19] = " << m1["Abc19"] << endl; // Note: inserted

	print("m1", m1);

	return 0;
}
