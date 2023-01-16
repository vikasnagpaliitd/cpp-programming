// ptr_to_arr : Point to dynamically allocated array of arrays (TwoD array)

#include <iostream>
using namespace std;

#define NUM_COLS 4
#define NUM_ROWS 2

int main()
{
  //int twod_arr[NUM_ROWS][NUM_COLS] = { {10, 20, 30, 40}, {11, 21, 31, 41}};
  int i,j;
  int (*ptr_to_arr)[NUM_COLS];
  
  ptr_to_arr = new int[NUM_ROWS][NUM_COLS];

  // Initialize elements via ptr_to_arr
  for(i = 0; i < NUM_ROWS; i++)
    for(j = 0; j < NUM_COLS; j++)
      //(*(ptr_to_arr + i))[j] = 100 * i + j;
      ptr_to_arr[i][j] = 100 * i + j;
  
  // Printing array
  for(i = 0; i < NUM_ROWS; i++)
  {
    for(j = 0; j < NUM_COLS; j++)
      cout << ptr_to_arr[i][j] << " ";
    cout << endl;
  }
  
  delete [] ptr_to_arr;
  return 0;
}
