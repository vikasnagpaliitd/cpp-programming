#include <iostream>
using namespace std;

#define NUM_ROWS 3 // could use MAX_ROWS too
#define NUM_COLS 4

int main()
{
  int matrix[NUM_ROWS][NUM_COLS]=
               {  
                {10, 11, 12, 13},
                {20, 21, 22, 23},
                {30, 31, 32, 33}
               };

  int i,j;

  for(i = 0; i < NUM_ROWS; i++)
  {
    for(j = 0; j < NUM_COLS; j++)
       cout << matrix[i][j]<< " ";
    cout << endl;
  }

  return 0;
}
