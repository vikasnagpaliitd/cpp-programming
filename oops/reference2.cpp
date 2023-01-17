// References: Reassigning reference changes the value, and not the reference itself.
#include <iostream>
using namespace std;

int main()
{
    int nValue = 10;
    int anotherValue = 20;
    int &vRef = nValue;

    cout << "nValue = " << nValue << endl;
    cout << "vRef = " << vRef << endl;

    cout << "&nValue = " << &nValue << endl;
    cout << "&vRef = " << &vRef << endl;


    // Note : Reassigning reference changes the value, and not the reference itself
    vRef = anotherValue; 
    cout << "After assigning anotherValue to vRef" << endl;

    cout << "nValue = " << nValue << endl;
    cout << "vRef = " << vRef << endl;

    cout << "&nValue = " << &nValue << endl;
    cout << "&vRef = " << &vRef << endl;

    return 0;
}
