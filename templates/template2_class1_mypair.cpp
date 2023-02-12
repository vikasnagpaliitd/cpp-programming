// Demonstrates : template class: MyPair : stores pair of elements
#include <iostream>
using namespace std;

template <class T1, class T2>
class MyPair
{
	private:
	T1 first;
	T2 second;

	public:

	typedef T1 FirstType;
	typedef T2 SecondType;

	MyPair(T1 a, T2 b) : first(a), second(b)
	{
	}

	T1 get_first() const // Ques: What if we wish to change first via this function?
	{
		return first;
	}

	T2 get_second() const
	{
		return second;
	}
};

int main()
{
	MyPair<int, string> mp1(10,"hello");
	MyPair<bool, bool> mp2(true, false);

	cout << "mp1: " << mp1.get_first() << ", " << mp1.get_second() << endl;
	cout << "mp2: " << mp2.get_first() << ", " << mp2.get_second() << endl;

	// Notice: nested types in a class. are very useful (for example) for iterators
	MyPair<int, string>::FirstType mp1_first  = mp1.get_first();
	MyPair<int, string>::SecondType mp1_second  = mp1.get_second();
	// Above way of declaring is very useful when you get MyPair object type as 
	//   a template parameter
	//FirstType mp1_first1; // will give compile error
	cout << "mp1_first = " << mp1_first << endl;
	cout << "mp1_second = " << mp1_second << endl;

	// use of auto
	//auto ptr_mp3 = new MyPair<string,string>("hello", "world"); // Note: notice auto
	MyPair<string,string>* ptr_mp3 = new MyPair<string,string>("hello", "world"); // its tough without auto
	cout << "*ptr_mp3: " << ptr_mp3->get_first() << ", " << ptr_mp3->get_second() << endl;
	delete ptr_mp3;


	// CTAD : Class Template Argument Deduction: c++17 onwards: automatic deduction. avoid if possible
	// auto ptr_mp4 = new MyPair(100, true); 
	// cout << "*ptr_mp4: " << ptr_mp4->get_first() << ", " << ptr_mp4->get_second() << endl;
	// delete ptr_mp4;

	return 0;
}
