// Added IntInputError and StringInputError, storing more information about the error
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

	// Ques: is what() virtual?
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


class IntInputError: public InputError
{
	private:
		int val;
		string what_string;

	public:

	IntInputError(string arg_msg, int int_val): InputError(arg_msg), val(int_val)
	{
		cout << "IntInputError:Constructor:msg = " << msg  << ", int_val = " << int_val << endl;
		what_string = arg_msg + ", val = "+ to_string(val);
	}

    const char* what() const throw() 
	{
		return what_string.c_str();
	}
};

class StringInputError: public InputError
{
	private:
		string val;
		string what_string;

	public:

	StringInputError(string arg_msg, string string_val): InputError(arg_msg), val(string_val)
	{
		cout << "StringInputError:Constructor:msg = " << msg  << ", string_val = " << string_val << endl;
		what_string = arg_msg + ", val = "+ val;
	}

    const char* what() const throw() 
	{
		return what_string.c_str();
	}
};

int main()
{
	try
	{
		//throw ApplicationError("Something wrong");
		//throw ProcessingError("Some Processing went wrong");
		throw IntInputError("Value of int is out of range", 100);
		//throw StringInputError("Length of string is too short", "hello");
	}
	catch (ApplicationError& app_error)
	//catch (ApplicationError app_error) // not recommended
	{
		cout << "Caught ApplicationError (or child): " << app_error.what() << endl;
	}

    return 0;
}
