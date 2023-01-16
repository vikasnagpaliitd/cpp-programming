// dptr pointing to scaler int*
#include <iostream>
using namespace std;

int main()
{
  int x=100;
  int *ptr = &x;
  int **dptr = &ptr;

  cout << "x=" << x << ", &x=" << &x << endl;
  cout << "ptr=" << ptr << ", &ptr=" << &ptr << endl;
  cout << "dptr=" << dptr << ", &dptr=" << &dptr << endl;
	
  cout << "**dptr=" << **dptr << endl;

  return 0;
}
