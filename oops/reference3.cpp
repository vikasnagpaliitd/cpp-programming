// References: Reference to const
#include <iostream>
using namespace std;

int main()
{
    int nValue = 10;
    const int nConstValue = 20;

    //experiment1: non-const reference being set to non-const data
    int    &vRef = nValue; //ok

    //experiment2: non-const reference being set to const data
    //int    &vRef = nConstValue; // not ok : non-const reference, referring to const variable

    //experiment3: const reference being set to const data
    //const int &vRef = nConstValue; // ok : but can not modify later

	//experiment4: const reference being set to non-const data
	//const int &vRef = nValue; // ok : const reference, referring to non-const variable : but can not modify later


    cout << "nValue = " << nValue << endl;
    cout << "nConstValue = " << nConstValue << endl;
    cout << "vRef = " << vRef << endl;

    // need to be commented in experiment3 and experiment4
    vRef = 11; 
    cout << "After assigning 11 to vRef" << endl;

    cout << "nValue = " << nValue << endl;
    cout << "nConstValue = " << nConstValue << endl;
    cout << "vRef = " << vRef << endl;

    return 0;
}
