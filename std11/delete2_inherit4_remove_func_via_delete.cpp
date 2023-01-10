//Demonstrates : Removing base class function in derived class (by making function private)
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
		void derived_func1()
		{
			cout << "derived_func1() called" << endl;
		}
		void identify() = delete;
  // protected:
//		using Base::identify; 
};
int main()
{
	Derived derived(7);
    cout << "identify on derived object : ";
    derived.identify();	
    cout << "derived_func1 on derived object : ";
    derived.derived_func1();	

	return 0;
}

