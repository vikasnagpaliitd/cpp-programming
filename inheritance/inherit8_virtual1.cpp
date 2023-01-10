#include <iostream>
using namespace std;


// Inheritance hierarchy A => B => C

class A
{
	protected:
	int a;

	public:
	A(int a)
	{
		this->a = a;
	}

	//virtual void display()
	void display()
	{
		cout << "A::display(): a = " << a << endl;
	}
};

class B : public A
{
	protected:
	int b;

	public:
	B(int a, int b) : A(a)
	{
		this->b = b;
	}

	//virtual void display()
	void display()
	{
		cout << "B::display(): a = " << a << endl;
		cout << "B::display(): b = " << b << endl;
	}
};

class C : public B
{
	protected:
	int c;

	public:
	C(int a, int b, int c) : B(a,b)
	{
		this->c = c;
	}

	void display()
	{
		cout << "C::display(): a = " << a << endl;
		cout << "C::display(): b = " << b << endl;
		cout << "C::display(): c = " << c << endl;
	}
};

int main()
{
	A obj_a(100);
	B obj_b(5,10);
	C obj_c(1,2,3);

	obj_a.display();
	obj_b.display();
	obj_c.display();


	cout << endl << endl;

	// Experiment  : Assigning derived class object to base class
    /*A obj_a1(10);
    obj_a1 = obj_b;
    obj_a1.display();*/

	// Experiment  : Assigning 2nd level derived class object to base class
    /*A obj_a1(10);
    obj_a1 = obj_c;
    obj_a1.display();*/


	//A &obj_a_ref = obj_b;
	A &obj_a_ref = obj_c;
	obj_a_ref.display();



	return 0;

}
