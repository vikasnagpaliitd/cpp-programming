// References: Reference to const
#include <iostream>
using namespace std;

int main()
{
    int nValue = 10;
    const int nConstValue = 20;

    int    &vRef = nValue; //ok
    //int    &vRef = nConstValue; // not ok : non-const reference, referring to const variable
    //const int &vRef = nConstValue; // ok : but can not modify later
	
	//const int &vRef = nValue; // ok : const reference, referring to non-const variable : but can not modify later


    cout << "nValue = " << nValue << endl;
    cout << "nConstValue = " << nConstValue << endl;
    cout << "vRef = " << vRef << endl;

    vRef = 11;
 
    cout << "After assigning 11 to vRef" << endl;

    cout << "nValue = " << nValue << endl;
    cout << "nConstValue = " << nConstValue << endl;
    cout << "vRef = " << vRef << endl;
    return 0;    


}
