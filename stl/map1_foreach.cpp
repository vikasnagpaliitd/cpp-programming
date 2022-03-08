// Copyright: Vikas Nagpal (Anuttara Learning)
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

void my_print(const pair<string, int>& p)
{
	cout << p.first << " : " << p.second << endl;
}

int main()
{
	map<string, int> m1;

	m1["Mohan"] = 12;
	m1["Sohan"] = 13;
	m1["Rohan"] = 14;

	for_each(m1.begin(), m1.end(), my_print);

	return 0;
}
