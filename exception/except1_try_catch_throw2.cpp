// Demonstrates: Nested try-catch
#include <iostream>
using namespace std;

int main()
{
	try 
	{
		try
		{
		    cout << "Inner block. Throwing exception" << endl;
			throw 100;// inner try-catch block should handle
			//throw string("hello"); // outer try-catch block should handle
			//throw 99.3; // not handled
		}
		catch(int e)
		{
			cout << "Inner block:Recieved int exception = " << e << endl;
		}
	}
	catch(string e)
	{
		cout << "Outer block:Recieved string exception = " << e << endl;
	}

  cout << "code after both blocks" << endl;

	return 0;
}
