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

	T1 get_first()
	{
		return first;
	}

	T2 get_second()
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

	auto ptr_mp3 = new MyPair<string,string>("hello", "world"); // Note: notice auto
	cout << "*ptr_mp3: " << ptr_mp3->get_first() << ", " << ptr_mp3->get_second() << endl;

	// Notice: nested types in a class. are very useful (for example) for iterators
	MyPair<int, string>::FirstType mp1_first  = mp1.get_first();
	MyPair<int, string>::SecondType mp1_second  = mp1.get_second();

	//FirstType mp1_first1; // will give compile error

	cout << "mp1_first = " << mp1_first << endl;
	cout << "mp1_second = " << mp1_second << endl;


	return 0;
}
