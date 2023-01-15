// What is a pointer?
// Explains pointer to scalar, array, dynamically allocated scaler, dynamically allocated array
#include <iostream>

#define MAX_ELEM 100

using namespace std;

int main()
{
  int xyz = 100;
  int *ptr;
  int arr[MAX_ELEM] = {10, 20, 30};

  ptr = &xyz; // variant1: address of xyz

  // ptr = arr; // variant2: base address of array arr

  // ptr = new int; // variant3: dynamic allocated scalar
  // ptr = new int [MAX_ELEM]; // variant4: dynamic allocatedarray
  // *ptr = 99; // variant3 and variant4

  cout << "xyz=" << xyz << endl;
  cout << "&xyz=" << &xyz << endl;
  cout << "ptr=" << ptr << endl;
  cout << "*ptr=" << *ptr << endl;
  cout << "&ptr=" << &ptr << endl;
  cout << "arr=" << arr << endl;

  //delete ptr; // variant3
  // delete [] ptr; // variant4
  return 0;
}
