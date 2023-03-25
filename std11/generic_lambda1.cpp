#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
void my_print(T x)
{
	cout << x << endl;
}

int main()
{
	vector<int> v1 = {10, 20, 30};
	vector<string> v2 = {"ab", "cd", "ef"};

    auto double_func = [](auto& elem) { elem = elem + elem;}; // generic lambda

	for_each(v1.begin(), v1.end(), double_func);
	for_each(v2.begin(), v2.end(), double_func);
	for_each(v1.begin(), v1.end(), my_print<int>);
	for_each(v2.begin(), v2.end(), my_print<string>);

    cout << "------------- Tripling now ---------------------" << endl;

    //auto triple_func = []<typename T>(T& elem) { elem = elem + elem + elem;}; // generic lambda. template based
    auto triple_func = []<class T>(T& elem) { elem = elem + elem + elem;}; // generic lambda. template based
	for_each(v1.begin(), v1.end(), triple_func);
	for_each(v2.begin(), v2.end(), triple_func);
	for_each(v1.begin(), v1.end(), my_print<int>);
	for_each(v2.begin(), v2.end(), my_print<string>);


	return 0;
}
