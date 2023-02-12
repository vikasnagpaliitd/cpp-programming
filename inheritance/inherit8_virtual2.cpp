// Demonstrates: Virtual destructor
// Inheritance hierarchy : C drives from B. B derives from A.
#include <iostream>
using namespace std;

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

	virtual ~A()
	//~A()
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
		//cout << "B::display(): a = " << a << endl;
		A::display();
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
		//cout << "C::display(): a = " << a << endl;
		//cout << "C::display(): b = " << b << endl;
		B::display();
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

	// Experiment  : Constructors,destructors in statically allocated objects
    /*
	A obj_a(100);
	B obj_b(5,10);
	C obj_c(1,2,3);

	obj_a.display();
    cout << "----------------" << endl;
	obj_b.display();
    cout << "----------------" << endl;
	obj_c.display();

	*/

    // Experiment: Ref to A referring to B. Or Ref to A referring to C
    /*
	B obj_b(5,10);
	A &obj_a_ref = obj_b;

	//C obj_c(1,2,3);
	//A &obj_a_ref = obj_c;

	//A &obj_a_ref = *new C(1,2,3); // Leak will happen as delete not called
	//obj_a_ref.display();
    */

    // Experiment: Pointer to A pointing to B
	/*
    A *obj_a_ptr = new B(5,10);
    delete obj_a_ptr;
    */

    // Experiment: Pointer to A pointing to C
	/*
    A *obj_a_ptr = new C(3, 5,10);
    delete obj_a_ptr;
    */

    // Experiment: Pointer to B pointing to C
    /*
	// invokes dtor of C even if ~B() not declared virtual (if ~A() is virtual)
	B *obj_b_ptr = new C(3, 5,10);
    delete obj_b_ptr;
    */

	return 0;
}
