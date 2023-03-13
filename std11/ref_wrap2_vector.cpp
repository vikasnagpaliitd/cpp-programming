#include <iostream>
#include <vector>
#include <functional>
using namespace std;


int main()
{
	//vector<int&> v1; // does not compile
	vector<reference_wrapper<int>> v1;
	int x = 10, y = 20;

	v1.push_back(ref(x));
	v1.push_back(ref(y));

	cout << "v1[0] = " << v1[0] << endl;
	cout << "v1[1] = " << v1[1] << endl;

	v1[0] ++;
	v1[1] ++;

	cout << "After incrementing v1[0] and v1[1]" << endl;
	cout << "v1[0] = " << v1[0] << endl;
	cout << "v1[1] = " << v1[1] << endl;
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;

	v1[0] = v1[1];
	v1[0]+=10;
	v1[1]+=10;

	cout << "After v1[0]=v1[1] and adding 10 to to both elements" << endl;
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;

	return 0;
}
