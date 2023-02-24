// Demonstrates: try catch throw mechanism
#include <iostream>
//#include <stdexcept> // Note: defines standard exceptions
using namespace std;

int main()
{

	try {
		cout << "Inside try block. Throwing exception" << endl;

		throw 100;
		//throw false;
		//throw string("hello");
		//throw "hello";
		//throw 99.304;
		// Note: we can throw object of a class too. Standard exceptions derive from exception class
    cout << "this code does not execute if exception thrown" << endl;
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
	catch(...) // catch all else // What if we place this as first handler block
	{
		cout << "Recieved some other (...)  exception" << endl;
	}

  cout << "This is the code after catching and handling exception" << endl;

	return 0;
}
