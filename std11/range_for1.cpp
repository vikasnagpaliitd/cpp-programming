#include <iostream>
#include <list>
#include <vector>
#include <map>
using namespace std;



int main()
{
	list<int> l1 = {1,2,3};
	vector<int> v1 = {4,5,6};
	int arr[] = {7,8,9};
	map<string, int> m1 = { {"Ram", 10}, {"Shyam", 12}};

	cout << "list:" << endl;
	for (auto i : l1) // Can use int or auto. Can also apply &(reference) and const
		cout << i << " ";
	cout << endl;

	cout << "vector:" << endl;
	for (auto i : v1) 
		cout << i << " ";
	cout << endl;

	cout << "array:" << endl; // works with array
	for (auto i : arr) 
		cout << i << " ";
	cout << endl;

	cout << "map:" << endl;
	for (auto [name, age] : m1) // structured binding // c++17
		cout << name << ":" << age << ", ";
	cout << endl;

	//func(arr);
	return 0;
}

void func(int arr[])
{
	cout << "array:" << endl;
	//for (auto i : arr) // range-for will not work here 
	//  cout << i << " ";
	cout << endl;

}
