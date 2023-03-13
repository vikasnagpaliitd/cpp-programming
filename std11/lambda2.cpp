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


	//for_each(v1.begin(), v1.end(), [](auto& x) {sum+= x;});  // does not compile
	//for_each(v1.begin(), v1.end(), [sum](auto& x) {sum+= x;});  // does not compile
	for_each(v1.begin(), v1.end(), [&sum](auto& x) {sum+= x;});  // does not compile
	cout << "sum = " << sum << endl;



	return 0;
}
