//Demonstrates : Removing base class function in derived class (by making function private)
#include <iostream>
using namespace std;

class Base
{
	public: // ideally should not be public
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
			cout << "Derived destructor called: m_value = " << m_value << endl;
			//cout << "Derived destructor called" << endl;
		}
		void derived_func1()
		{
			cout << "derived_func1() called" << endl;
		}
   private:
		//using Base::identify; 
        //using Base::m_value;
};

int main()
{
	Derived derived(7);
    cout << "identify on derived object : ";
    derived.identify();	
    cout << "derived_func1 on derived object : ";
    derived.derived_func1();	
    cout << "derived.m_value = " << derived.m_value << endl;

	return 0;
}

