//Demonstrates : reusing base class function in derived class, Order of constructor, Order of destructor
#include <iostream>
using namespace std;

class Base
{
	protected:
	    int m_value;

	public:
	    Base(int value) : m_value(value)
		{
			cout << "Base constructor called" << endl;
		}
		~Base()
		{
			cout << "Base destructor called" << endl;
		}
	//private:
	//protected:
	    void identify() // Ques: What if this function is private? What if this is protected
		{ 
			cout << "I am Base\n";
		}
};

class Derived: public Base 
{
	public:
	    Derived(int value) : Base(value) 
		{
			cout << "Derived constructor called" << endl;
		}
		~Derived()
		{
			cout << "Derived destructor called" << endl;
		}
};
int main()
{
    Base base(5);
    base.identify();	// I am Base

	Derived derived(7);
    derived.identify();	// I am Base
	return 0;
}

