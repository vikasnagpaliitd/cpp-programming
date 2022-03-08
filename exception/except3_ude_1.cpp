// Copyright: Vikas Nagpal (Anuttara Learning)
// User Defined Exception
#include <iostream>
#include <exception>
using namespace std;


class ApplicationError : public exception
{
	string msg;

	public:

	ApplicationError(string arg_msg) : msg(arg_msg)
	{
		cout << "ApplicationError:Constructor:msg = " << msg << endl;
	}

    const char* what() const throw() 
	{
		return msg.c_str();
	}
};

int main()
{
	try
	{
		throw ApplicationError("Something wrong");
	}
	catch (ApplicationError& app_error)
	{
		cout << "Caught ApplicationError: " << app_error.what() << endl;
	}

	return 0;
}
