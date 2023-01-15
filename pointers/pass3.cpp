// What if a function wishes to modify a pointer?
#include <iostream>
using namespace std;
#define MAX_ELEM 10

// Will the pointer increment persist after the function returns?
void increment(int *p_arg)
{
  p_arg++;
}

int main()
{
  int arr[MAX_ELEM] = {10,20,30,40,50};
  int *ptr = arr;
  cout<<"Before increment: ptr[0]=" << ptr[0] << endl;
  increment(ptr);
  cout<<"After increment: ptr[0]=" << ptr[0] << endl;
  
  return 0;
}
