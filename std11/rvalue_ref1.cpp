#include <iostream>
using namespace std;

int main()
{
    int xyz = 10;
    int& ref = xyz;

    // does not compile // non-const reference can not refer to temporary object
    //int& ref2 = 13; // does not compile // non-const reference can not refer to constant(temporary) object

    const int& ref3 = 15; // const lvalue reference can refer to constant objects

    const int cnum=100;
    int&& rvalue_ref = 20; // r-value reference can refer to temporary
    //int&& rvalue_ref = cnum; // Error:r-value reference can not refer to to constant lvalue
    //int&& rvalue_ref2 = xyz; // Error:r-value reference can not refer to lvalue

    //cout << "ref = " << ref << endl;
    //cout << "ref3 = " << ref3 << endl;    
    cout << "rvalue_ref = " << rvalue_ref << endl;   
    rvalue_ref++;  // mutable reference : can change the data even of temporary object
    cout << "After increment: rvalue_ref = " << rvalue_ref << endl; 

    return 0;
}

