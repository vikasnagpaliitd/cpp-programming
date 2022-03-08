// Copyright: Vikas Nagpal (Anuttara Learning)
#include <iostream>
#include <array>
#include <algorithm>
#include <functional>
using namespace std;



int main()
{
	array<int,5> arr = {11,-22,33,-44,55};
	int n_arr[] = {11,-22,33,-44,55};


	cout << "arr[2]	= " << arr[2] << endl;
	cout << "arr.at(4)	= " << arr.at(4) << endl;
	//cout << "arr.at(5)	= " << arr.at(5) << endl; // out of bound index


	cout << "arr.front()	= " << arr.front()  << endl;
	cout << "arr.back()	= " << arr.back()  << endl;

	//sort(arr.begin(), arr.end());
	sort(arr.begin(), arr.end(), greater<int>());

	//sort(n_arr, n_arr+5);
	sort(n_arr, n_arr+5, greater<int>());
	for(auto k : n_arr)
		cout << k << " ";
	cout <<endl;
	

}
