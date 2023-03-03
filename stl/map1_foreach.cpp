#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

#if 0
void my_print(const pair<string, int>& p)
{
	cout << p.first << " : " << p.second << endl;
}
#endif

#if 1
template<typename Pair>
void my_print(const Pair& p)
{
	cout << p.first << " : " << p.second << endl;
}
#endif

int main()
{
	map<string, int> m1;

	m1["Mohan"] = 12;
	m1["Sohan"] = 13;
	m1["Rohan"] = 14;

	for_each(m1.begin(), m1.end(), my_print<pair<string,int>>);

	return 0;
}
