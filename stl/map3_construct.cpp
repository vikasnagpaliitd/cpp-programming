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

	auto it1 = m1.find("Abc2");
	auto it2 = m1.find("Abc9");

	//it1++; // ok
	map<string, int> m2(it1, it2);
	///map<string, int> m2(it1+1, it2);// does not compile

	print("m1", m1);
	print("m2", m2);


	map<string,int> m3({{"V1", 1}, {"V2", 2}, {"V3", 3}}); // Initializer list
	print("m3", m3);


	return 0;
}
