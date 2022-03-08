// Copyright: Vikas Nagpal (Anuttara Learning)
#include <iostream>
#include <stdexcept> // Note: defines standard exceptions
using namespace std;

int main()
{

	try {
		cout << "Inside try block. Throwing exception" << endl;

		throw 100;
		//throw false;
		//throw string("hello");
		//throw 99.304;
		// Note: we can throw object of a class too. Standard exceptions derive from exception class


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
