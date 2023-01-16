// ptr_to_arr : Point to an array of array (i.e. twod array)
#include <iostream>
using namespace std;

#define NUM_COLS 4
#define NUM_ROWS 2

int main()
{
  int twod_arr[NUM_ROWS][NUM_COLS] = { {10, 20, 30, 40}, {11, 21, 31, 41}};
  int i,j;
  //int (*ptr_to_arr)[NUM_COLS] = &twod_arr; // warning: incompatible pointer
  int (*ptr_to_arr)[NUM_COLS] = twod_arr;

  // Adding 100 to each element via ptr_to_arr
  for(i = 0; i < NUM_ROWS; i++)
    for(j = 0; j < NUM_COLS; j++)
      ptr_to_arr[i][j] += 100;
      //(*(ptr_to_arr + i))[j] += 100;

  
  // Printing array
  for(i = 0; i < NUM_ROWS; i++)
  {
    for(j = 0; j < NUM_COLS; j++)
      cout << twod_arr[i][j] << " ";
    cout << endl;
  }
  
  return 0;
}
