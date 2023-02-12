//Demonstrates: MyStack : Gave default value for max_stack_len
#include <iostream>
using namespace std;

template <class T,int max_stack_len=3>
class MyStack
{
	private:

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

int main()
{
	try
	{
	 	//MyStack<string, 2> s_stack;
		MyStack<string, 3> s_stack;
	 
	 	s_stack.push("one");
	 	s_stack.push("two");
	 	s_stack.push("three");
	 	//s_stack.push("four"); // will raise exception as stack full
	 
	 
	 	MyStack<int> i_stack; // Note: default parameter gets used here
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
