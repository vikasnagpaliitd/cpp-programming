// ptr_to_arr : Point to an array
#include <iostream>
using namespace std;

#define NUM_COLS 4

int main()
{
  int array[NUM_COLS] = {10, 20, 30, 40}, i;
  int (*ptr_to_arr)[NUM_COLS] = &array; // pointer to array
  //int (*ptr_to_arr)[NUM_COLS] = array; // experiment1: warning: incompatible pointer

  printf("sizeof(ptr_to_arr)=%ld\n", sizeof(ptr_to_arr)); // 8
  printf("sizeof(array)=%ld\n", sizeof(array)); // 4 * sizeof(int)
  printf("sizeof(*ptr_to_arr)=%ld\n", sizeof(*ptr_to_arr)); //4 * sizeof(int)
  
  

  // Adding 100 to each element via ptr_to_arr
  for(i = 0; i < NUM_COLS; i++)
      ptr_to_arr[0][i] += 100;
      //(*(ptr_to_arr+0))[i] += 100;
      //(*ptr_to_arr)[i] += 100;
  

  // Printing array
  for(i = 0; i < NUM_COLS; i++)
      cout << array[i] << " ";
  cout << endl;

  cout << "experiment2: increment shifts by sizeof(array)" << endl;
  cout << "ptr_to_arr=" << ptr_to_arr << endl;
  ptr_to_arr ++; // notice, it will point to invalid memory after increment
  cout << "after increment: ptr_to_arr=" << ptr_to_arr << endl;
  return 0;
}
