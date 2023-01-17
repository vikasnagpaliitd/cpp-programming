// References: r-value references
#include <iostream>
using namespace std;

int main()
{
    int nValue = 10;

    int    &&vRef = 49; // C++11 : rvalue reference

    cout << "nValue = " << nValue << endl;
    cout << "vRef = " << vRef << endl;
    cout << "&nValue = " << &nValue << endl;
    cout << "&vRef = " << &vRef << endl;
 
    return 0;
}
