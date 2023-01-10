#include <iostream>
#include <stdexcept> // Note: defines standard exceptions
using namespace std;

int main()
{

	try {
		int *ptr = new int[99999999999];

	}
	//catch(exception &e)
	catch(exception e) // Ques: What is difference between using exception& vs exception
	//catch(const exception &e)
	//catch(...)
	{
		cout << "Recieved exception = " << e.what() << endl;
		//cout << "Recieved exception = "  << endl;
	}


	return 0;
}
