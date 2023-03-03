// Demo : insert() : overload 1 and 3
#include <iostream>
#include <map>
using namespace std;

template <class M>
void print(string name, const M& m)
{
	cout << name << endl;
	for(auto i:m)
		cout << i.first << " " << i.second << endl;
	cout << endl;
}

int main()
{
	map<string, int> m1 { {"aaa", 1}, {"ddd", 4}, {"bbb", 2}, {"ccc", 3},  };

	print("m1", m1);

	// Overload 1
	// Insert a value (pair)
	pair<string, int> elem1("abc", 21);
	//pair<map<string,int> :: iterator, bool> ret;
	//ret = m1.insert(elem1);
	auto ret = m1.insert(elem1); //Note: can be used instead of declaring the complex data type of ret

	cout << "insert pair(abc,21). Return: ret.first->first = " << ret.first->first << ", ret.first->second = " << ret.first->second << ", ret.second = " << std::boolalpha<< ret.second << endl;
	print("m1", m1); // Note: we are getting sorted order listing


	// C++17 allows structured binding to further simplify code
	pair<string, int> elem2("abd", 22);
	auto [it, status] = m1.insert(elem2); // structured binding
	cout << "insert pair(abd,22). Return: it->first = " << it->first << ", it->second = " << it->second << ", status = " << status << endl;
	print("m1", m1); // Note: we are getting sorted order listing

	// Overload 3 and 8: Writing very simple code
	{
		// Below few commented lines, just to clarify what is rvalue reference.
		//pair<string, int> elem2("abe", 23);
		//pair<string, int> && rvalue_ref = {"ddd", 9}; // rvalue reference can be bound to a temporary(ephemeral)
		//pair<string, int> && rvalue_ref = elem2; //does not compile
		//cout << "rvalue_ref.first = " << rvalue_ref.first  << ", rvalue_ref.second = " << rvalue_ref.second  << endl;

		auto [it, status] = m1.insert(pair<string,int>("abe", 23)); // Overload 3
		//auto [it, status] = m1.insert({"abe", 23}); // Overload 8
		cout << "insert pair(abe,23). Return: it->first = " << it->first << ", it->second = " << it->second << ", status = " << status << endl;
		print("m1", m1); // Note: we are getting sorted order listing
	}

	// What happens if element is already present? status becomes false, and it refers to existing element

	// Inserting same key twice
	{
		auto [it, status] = m1.insert({"abe", 99}); 
		cout << "insert pair(abe,99). Return: it->first = " << it->first << ", it->second = " << it->second << ", status = " << status << endl;
		print("m1", m1); // Note: we are getting sorted order listing
	}

	return 0;
}
