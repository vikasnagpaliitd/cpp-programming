#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void my_print(int x)
{
	cout << x << endl;
}

int main()
{
	vector<int> v1;

	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);


	for_each(v1.begin(), v1.end(), [](auto& x) { x *= 2; x*= 3;}); // multiply by 6
	for_each(v1.begin(), v1.end(), my_print);



	return 0;
}
