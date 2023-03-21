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

	int sum=0;

	//for_each(v1.begin(), v1.end(), [](const auto& x) {sum += x;});  // Error: sum is not captured
	//for_each(v1.begin(), v1.end(), [sum](const auto& x) {sum += x;});  // Error: assignment of read-only variable ‘sum’
	for_each(v1.begin(), v1.end(), [&sum](const auto& x) {sum += x;});  // Works
	//for_each(v1.begin(), v1.end(), [=](const auto& x) {sum += x;});  // Error:
	//for_each(v1.begin(), v1.end(), [&](const auto& x) {sum += x;});  // Works

	cout << "sum = " << sum << endl;

	return 0;
}
