// References: Introduction
#include <iostream>
using namespace std;

int main()
{
    int nValue = 10;

    //int& vRef; // Error : Reference must be initialized
    int    &vRef = nValue;

    cout << "nValue = " << nValue << endl;
    cout << "vRef = " << vRef << endl;
    cout << "&nValue = " << &nValue << endl;
    cout << "&vRef = " << &vRef << endl;
    vRef = 11;
 
    cout << "After assigning 11 to vRef" << endl;

    cout << "nValue = " << nValue << endl;
    cout << "vRef = " << vRef << endl;
    cout << "&nValue = " << &nValue << endl;
    cout << "&vRef = " << &vRef << endl;
    return 0;    


}
