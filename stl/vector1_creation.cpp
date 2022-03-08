// Copyright: Vikas Nagpal (Anuttara Learning)
#include <iostream>
#include <vector>
using namespace std;


int main()
{
	vector<string> v1(5, "hello"); // 5 times hello
	//vector<string> v1 {"life", "is", "good"}; // List initializtion : such syntax works only after C++11

	// Try: auto
	for (vector<string>::iterator i = v1.begin(); i != v1.end(); i++) // Try: < instead of !=. < end -1 instead of < end 
	{
		cout <<  *i << endl;
	}

	//vector<string> v2 {v1.begin(), v1.end()};
	vector<string> v2 (v1.begin(), v1.end() - 2);
	cout << "v2 vector:" << endl;
	//for (vector<string>::iterator i = v2.begin(); i != v2.end(); i++) 
	for (auto i : v2) // range-based for loop
	{
		cout <<  i << endl;
	}


	return 0;

}
