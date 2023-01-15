// Passing 2D array to function
#include <iostream>
using namespace std;

#define NUM_ROWS 3
#define NUM_COLS 4

//void func(int arr[100]) // array of 
///void func(int arr[])
//void func(int *arr)

//void display_matrix(int matrix[NUM_ROWS][NUM_COLS])
//void display_matrix(int matrix[ ][NUM_COLS])
void display_matrix(int (*matrix)[NUM_COLS])

{
  int i,j;

  cout << "matrix=" << matrix << endl;

  cout << "The matrix is:" << endl;
  for(i = 0; i < NUM_ROWS; i++)
  {
    for(j = 0; j < NUM_COLS; j++)
      cout << matrix[i][j] << " ";
    cout << endl;
  }

  //experiment1
  cout << "sizeof(matrix)=" << sizeof(matrix) << endl;
  cout << "sizeof(matrix[0])=" << sizeof(matrix[0]) << endl;

  // experiment2
  matrix++; // does compile!
  cout << "after increment: matrix=" << matrix << endl;

}

int main()
{
  int matrix[NUM_ROWS][NUM_COLS]=
               {  
                {10, 11, 12, 13},
                {20, 21, 22, 23},
                {30, 31, 32, 33}
               };

  display_matrix(matrix);

  return 0;
}
