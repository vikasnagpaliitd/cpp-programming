// returning a pointer from function using output argument
#include <iostream>
using namespace std;

// Return array having 1st 'n' natural numbers
void get_natural_num_list(int n, int **p_ptr)
{
   int *arr, i;

   arr = new int [n];

   for(i=0;i<n;i++)
     arr[i] = i+1;

   *p_ptr = arr;
}

int main()
{
  int *ret, i, n = 10;
  get_natural_num_list(n, &ret);
  for(i=0;i<n;i++)
    cout << ret[i] << " ";
  cout << endl;

  delete [] ret;
  
  return 0;
}
