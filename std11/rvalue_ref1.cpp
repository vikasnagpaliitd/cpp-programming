// Copyright: Vikas Nagpal (Anuttara Learning)
#include <iostream>
using namespace std;

int main()
{
    int xyz = 10;
    int& ref = xyz;
    //int& ref2 = 15; // does not compile // non-const reference can not refer to constant object
    const int& ref3 = 15; // works

    int&& rvalue_ref = 20;
    //int&& rvalue_ref2 = xyz; // does not compile

    //cout << "ref = " << ref << endl;
    //cout << "ref3 = " << ref3 << endl;    
    cout << "rvalue_ref = " << rvalue_ref << endl;   
    rvalue_ref++;  // mutable reference
    cout << "After increment: rvalue_ref = " << rvalue_ref << endl; 

    return 0;
}

