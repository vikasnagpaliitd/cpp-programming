// Returning 2D array from a function using pointer argument
#include <iostream>
using namespace std;

#define NUM_ROWS 3
#define NUM_COLS 4


void display_matrix(int matrix[ ][NUM_COLS])
{
  int i, j;
  for(i = 0; i < NUM_ROWS; i++)
  {
    for(j = 0; j < NUM_COLS; j++)
      cout << matrix[i][j] << " ";
    cout << endl;
  }
}

//experiment1
//typedef int row_arr_t[NUM_COLS];


//int (*)[NUM_COLS] alloc_n_init_matrix() // does not compile
//int (* alloc_n_init_matrix())[NUM_COLS] // works
//row_arr_t * alloc_n_init_matrix() // works and is intuitive//experiment1
void alloc_n_init_matrix(int (**p_ptr)[NUM_COLS]) // double pointer to return a pointer
{
  // allocate 2D matrix
  int (*ptr)[NUM_COLS];
  int i,j;

  //variant1: allocate 2D array
  ptr = new int[NUM_ROWS][NUM_COLS];

  //variant2: allocate as a sequential 1D array of NUM_ROWS * NUM_COLS 
  //ptr = (int (*)[NUM_COLS]) new int[NUM_ROWS * NUM_COLS]; // Notice error if no typecasting

  //variant3: we could have filled it using single (int*) pointer and 
  //  returned a typecasted pointer to array

  //variant4: we could have filled it using single (int*) pointer and 
  //  returned a single pointer, and calling function would typecast to
  //  pointer to array

  // Fill it
  for(i = 0; i < NUM_ROWS; i++)
    for(j = 0; j < NUM_COLS; j++)
	  ptr[i][j]= 100 * i + j;

  // Store in output argument
  *p_ptr = ptr;

}

int main()
{
  //int matrix[NUM_ROWS][NUM_COLS];
  int (*matrix)[NUM_COLS];

  alloc_n_init_matrix(&matrix);

  display_matrix(matrix);

  //variant1 and variant2
  delete [] matrix;
  return 0;
}
