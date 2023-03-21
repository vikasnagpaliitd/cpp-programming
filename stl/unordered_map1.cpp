#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	//map<string, int> m1;
	unordered_map<string, int> m1{{"Mohan", 12}, {"Sohan", 13}, {"Rohan", 14}};

	m1["Mohan"] = 112;
	m1["Sohan"] = 113;
	m1["Rohan"] = 114;

	//m1.insert(make_pair("Tom", 40));
	m1.insert(pair<string,int>("Tom", 40));
	//m1.insert({"Tom", 40});


	for(auto i = m1.begin(); i != m1.end(); i++)
		cout << i->first << " : " << i->second << endl;


	unordered_map<string, int> m2(m1.begin(), m1.end());
	cout << "m2 map:" << endl;

#if 1
	for(auto i : m2)
		cout << i.first << " : " << i.second << endl;
#endif

	return 0;
}
