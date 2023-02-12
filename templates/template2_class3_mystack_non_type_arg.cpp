//Demonstrates: MyStack: non-type argument for giving dimension
#include <iostream>
using namespace std;

template <class T,int max_stack_len>
class MyStack
{
	private:

	//Removed:static const int max_stack_len;
	T arr[max_stack_len];
	int top; //Indicates index tilll which stack is filled

	public:

	MyStack()
	{
		top = -1;
	}
	
	bool is_empty()
	{
		return (top == -1);
	}

	bool is_full()
	{
		return (top == (max_stack_len - 1));
	}

	void push(T val)
	{
		if (is_full())
			throw string("exception:push in full stack"); // Normally exception object would be thrown

		arr[++top] = val;
	}

	T pop()
	{
		if (is_empty())
			throw string("exception:pop in empty stack"); // Normally exception object would be thrown

		return arr[top--];
	}
};

/* Removed: template <class T>
const int MyStack<T>::max_stack_len = 3; // Small value so that stack actually can get full
*/


int main()
{
	try
	{
	 	MyStack<string, 3> s_stack;
	 
	 	s_stack.push("one");
	 	s_stack.push("two");
	 	s_stack.push("three");
	 	//s_stack.push("four"); // will raise exception as stack full
	 
	 	MyStack<int, 3> i_stack;
	 	i_stack.push(10);
	 	i_stack.push(20);
	 	i_stack.push(30);
	 
	 	cout << "Popping after pushing 10,20,30" << endl;
	 	cout << i_stack.pop() << endl;
	 	cout << i_stack.pop() << endl;
	 	cout << i_stack.pop() << endl;
	 	cout << i_stack.pop() << endl;
	}
	catch (string& s)
	{
		cout << s << endl;
	}

	return 0;
}
