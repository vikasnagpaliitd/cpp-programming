// sizeof 2D array, sizeof row
#include <iostream>
using namespace std;

#define NUM_ROWS 3
#define NUM_COLS 4

int main()
{
  int matrix[NUM_ROWS][NUM_COLS]=
               {  
                {10, 11, 12, 13},
                {20, 21, 22, 23},
                {30, 31, 32, 33}
               };

  cout << "sizeof(matrix)=" << sizeof(matrix) << endl;
  cout << "sizeof(matrix[0])=" << sizeof(matrix[0]) << endl;
  cout << "sizeof(matrix[0][0])=" << sizeof(matrix[0][0]) << endl;

  return 0;
}
