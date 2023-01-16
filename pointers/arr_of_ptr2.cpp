//Array of pointers: pointing to Arrays
#include <iostream>
using namespace std;

#define NUM 3
#define DIM_ARR 2

int main()
{
  int x_arr[DIM_ARR] = {10, 11};
  int y_arr[DIM_ARR] = {20, 21};
  int z_arr[DIM_ARR] = {30, 31};
  int i, j;

  int *arr_of_ptr[NUM] = {x_arr, y_arr, z_arr};

  for(i = 0; i < NUM; i++)
  {
    printf("Contents of row %d : ", i);
    for(j = 0; j < DIM_ARR; j++)
       cout << arr_of_ptr[i][j] << " ";
	 cout << endl;
  }
  return 0;
}
