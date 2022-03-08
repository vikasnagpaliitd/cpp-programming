// Copyright: Vikas Nagpal (Anuttara Learning)
// Hierarchy : ProcessingError and InputError inherit from ApplicationError
#include <iostream>
#include <exception>
using namespace std;


class ApplicationError : public exception
{
	protected: // Note: made it protected
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

class ProcessingError : public ApplicationError
{
	public:

	ProcessingError(string arg_msg): ApplicationError(arg_msg)
	{
		cout << "ProcessingError:Constructor:msg = " << msg << endl;
	}
};


class InputError : public ApplicationError
{
	public:

	InputError(string arg_msg): ApplicationError(arg_msg)
	{
		cout << "InputError:Constructor:msg = " << msg << endl;
	}
};


int main()
{
	try
	{
		//throw ApplicationError("Something wrong");
		//throw InputError("Value of X is out of range");
		throw ProcessingError("Some Processing went wrong");
	}
	catch (ApplicationError& app_error)
	{
		cout << "Caught ApplicationError (or child): " << app_error.what() << endl;
	}

}
