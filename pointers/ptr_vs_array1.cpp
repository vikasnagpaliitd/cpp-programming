// Pointer vs 1D array
#include <iostream>
using namespace std;

int main()
{
  
  int arr[100];
  int *ptr = arr;


  cout << "experiment1: size" << endl;
  cout << "sizeof(ptr)=" << sizeof(ptr) << endl;
  cout << "sizeof(arr)=" << sizeof(arr) << endl << endl;

  cout << "experiment2: numeric address value" << endl;
  cout << "ptr=" << ptr << endl;
  cout << "arr=" << arr << endl << endl;

  cout << "experiment3: can increment ptr but not array" << endl;
  ptr++;
  cout << "after increment: ptr=" << ptr << endl;
  //arr++; // does not compile
  //arr = arr + 10; // does not compile
  

  return 0;

}
