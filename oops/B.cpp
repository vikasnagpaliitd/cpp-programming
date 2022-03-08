// Copyright: Vikas Nagpal (Anuttara Learning)
#include <iostream>
using namespace std;

class B
{
	public:
	B(const char* str = "\0") //default constructor 
    {
		cout << "Constructor called" << endl;
	}
	B(const B &b)  //copy constructor 
    {
		cout << "Copy constructor called" << endl;
	} 
};
int main() { 
	B ob1 = "copy me"; 
	B ob2 = ob1; // ??
	B ob3 = 34; //??
	return 0;
}

