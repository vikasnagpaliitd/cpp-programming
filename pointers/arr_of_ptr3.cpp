// Symmetrix matrix: store half
#include <iostream>
using namespace std;

#define N 10 // number of rows/columns

#if 0
struct node
{
  int val;
  int col;
  struct node *next;
};
#endif

int main()
{

  //struct node *matrix[N]; // array of pointers
  int *matrix[N];
  int i, j;

  // allocate space
  for(i = 0; i < N; i++)
  {
      matrix[i] = new int[i + 1];
      for (j = 0; j <= i; j++)
         matrix[i][j] = 100 *i + j;
  }

  for(i = 0; i < N; i++)
  {
      for (j = 0; j <= i; j++)
         cout << matrix[i][j] << " ";
      cout << endl;
  }

  // deallocate space
  for(i = 0; i < N; i++)
      delete [] matrix[i];

  return 0;
}
