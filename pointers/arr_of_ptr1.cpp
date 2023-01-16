//Array of pointers: pointing to scalers
#include <iostream>
using namespace std;

#define NUM 3

int main()
{
  int x = 10, y = 20, z = 30;
  int i;

  int *arr_of_ptr[NUM] = {&x, &y, &z};

  cout << "&x=" << &x << endl;
  cout << "&y=" << &y << endl;
  cout << "&z=" << &z << endl;

  for(i = 0; i < NUM; i++)
  {
    cout << "arr_of_ptr[" << i << "]=" << arr_of_ptr[i] << endl;
    cout << "*arr_of_ptr[" << i << "]=" << *arr_of_ptr[i] << endl;
  }

  return 0;
}
