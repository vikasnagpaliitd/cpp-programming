// Symmetrix matrix: even allocate array of pointers dynamically
#include <iostream>
using namespace std;

//#define N 100000 // number of rows/columns

int main()
{
   //int *matrix[N]; // commented as it will be allocated dynamically
   int **matrix;
   int num=10;
  
   // Change :
    // 1) matrix becomes pointer to int*
    // 2) dynamically allocate array of num int pointers
  
  matrix = new int*[num];
  
  int i, j;

  // allocate space
  for(i = 0; i < num; i++)
  {
    matrix[i] = new int[i + 1];
    for (j = 0; j <= i; j++)
      matrix[i][j] = 100 *i + j;
  }

  for(i = 0; i < num; i++)
  {
    for (j = 0; j <= i; j++)
     cout << matrix[i][j] << " ";
    cout << endl;
  }

  // deallocate space
  for(i = 0; i < num; i++)
      delete [] matrix[i];
  
  // need to free the (dynamically allocated) array of pointers
  delete [] matrix;

  return 0;
}
