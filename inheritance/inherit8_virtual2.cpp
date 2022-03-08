// Copyright: Vikas Nagpal (Anuttara Learning)
// Virtual destructor
#include <iostream>
using namespace std;


// Inheritance hierarchy A => B => C

class A
{
	protected:
	int a;
	int * arr_a;

	public:
	A(int a)
	{
		this->a = a;
		arr_a = new int[a];
	}

	//virtual void display()
	void display()
	{
		cout << "A::display(): a = " << a << endl;
	}

	//virtual ~A()
	~A()
	{
		cout << "Destructor:A" << endl;
		delete [] arr_a;
	}
};

class B : public A
{
	protected:
	int b;
	int * arr_b;

	public:
	B(int a, int b) : A(a)
	{
		this->b = b;
		arr_b = new int[b];
	}

	//virtual void display()
	void display()
	{
		cout << "B::display(): a = " << a << endl;
		cout << "B::display(): b = " << b << endl;
	}
	~B()
	{
		cout << "Destructor:B" << endl;
		delete [] arr_b;
	}
};

class C : public B
{
	protected:
	int c;
	int * arr_c;

	public:
	C(int a, int b, int c) : B(a,b)
	{
		this->c = c;
		arr_c = new int[c];
	}

	void display()
	{
		cout << "C::display(): a = " << a << endl;
		cout << "C::display(): b = " << b << endl;
		cout << "C::display(): c = " << c << endl;
	}
	~C()
	{
		cout << "Destructor:C" << endl;
		delete [] arr_c;
	}
};

int main()
{
/*	A obj_a(100);
	B obj_b(5,10);
	C obj_c(1,2,3);

	obj_a.display();
	obj_b.display();
	obj_c.display();


	cout << endl << endl; */

	// Experiment  : Assigning derived class object to base class
    /*A obj_a1(10);
    obj_a1 = obj_b;
    obj_a1.display();*/

	// Experiment  : Assigning 2nd level derived class object to base class
    /*A obj_a1(10);
    obj_a1 = obj_c;
    obj_a1.display();*/


	//A &obj_a_ref = obj_b;
	/*A &obj_a_ref = obj_c;
	obj_a_ref.display();*/

	/*A *obj_a_ptr = new B(5,10);
    delete obj_a_ptr;*/


	/*A *obj_a_ptr = new C(3, 5,10);
    delete obj_a_ptr;*/

	B *obj_b_ptr = new C(3, 5,10);
    delete obj_b_ptr;

	return 0;

}
