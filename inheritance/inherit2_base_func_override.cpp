//Demonstrates : Redefining base class function in derived class
#include <iostream>
using namespace std;

class Base
{
	protected:
	    int m_value;

	public:
	    Base(int value) : m_value(value)
		{
			//cout << "Base constructor called" << endl;
		}
		~Base()
		{
			//cout << "Base destructor called" << endl;
		}
	    void identify()
		{ 
			cout << "I am Base\n";
		}
};

class Derived: public Base 
{
	public:
	    Derived(int value) : Base(value) 
		{
			//cout << "Derived constructor called" << endl;
		}
		~Derived()
		{
			//cout << "Derived destructor called" << endl;
		}
	    void identify() // Derived class redefines this function
		{ 
			cout << "I am Derived\n";
		}
};

int main()
{
    Base base(5);
    cout << "identify on base object : ";
    base.identify();	// I am Base

	Derived derived(7);
    cout << "identify on derived object : ";
    derived.identify();	// I am Derived

    Base &base_ref1 = base;
    cout << "identify on base reference referring to base object: ";
    base_ref1.identify(); // ??

    Base &base_ref2 = derived;
    cout << "identify on base reference referring to derived object: ";
    base_ref2.identify(); // ??

    //Ques: What if we used pointers instead of references?

	return 0;
}

