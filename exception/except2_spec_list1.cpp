#include <iostream>
#include <stdexcept> // Note: defines standard exceptions
using namespace std;


class Marker
{
	string s;

	public:
	Marker(string arg_s) : s(arg_s)
	{
		cout << "Constructor for " << s << endl;
	}

	~Marker()
	{
		cout << "Destructor for " << s << endl;
	}

};

//void func2() throw(int, string)
//void func2() throw() // should not throw any exception
//void func2() noexcept
//void func2() noexcept(true)
void func2() noexcept(false)
//void func2()  // can throw any exception
{
	Marker m("func2");
    throw 100;
	//throw false; // Ques: What if a function throws some exception not specified
}

void func1()
{
	Marker m("func1");
	func2();

}

int main()
{
	Marker m("main");


	try {
		func1();


	}
	catch(int e)
	{
		cout << "Recieved int exception = " << e << endl;
	}
	catch(string e)
	{
		cout << "Recieved string exception = " << e << endl;
	}
	catch(bool e)
	{
		cout << "Recieved bool exception = " << e << endl;
	}
	catch(...) // catch all else
	{
		cout << "Recieved some other (...)  exception" << endl;
	}

	return 0;
}
