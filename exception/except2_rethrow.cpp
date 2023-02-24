// Demonstrates : rethrow of caught exception
#include <iostream>
using namespace std;

// Class to mark function calls and (exception based) returns
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

void func2()
{
	Marker m("func2");
    throw 100;
}

void func1()
{
	Marker m("func1");
	try {
	    func2();
	}
	catch(int e)
	{
		cout << "func1: caught int exception = " << e << ". doing throw..." << endl;
		throw; // (re)throw same exception
		//throw string("hello"); // create and throw a new exception
	}
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
	catch(...) // catch all else
	{
		cout << "Recieved some other (...)  exception" << endl;
	}

	return 0;
}
