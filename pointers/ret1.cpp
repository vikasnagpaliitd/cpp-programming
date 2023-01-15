// returning a pointer from function
// It could be pointer to scalar , or could be an array
// The data should "exist" after the function returns

#include <iostream>
using namespace std;

// Return array having 1st 'n' natural numbers
int* get_natural_num_list(int n)
{
   int *arr, i;

   arr = new int [n];

   for(i=0;i<n;i++)
     arr[i] = i+1;

   return arr;
}

int main()
{
  int *ret, i, n = 10;
  ret = get_natural_num_list(n);
  for(i=0;i<n;i++)
    cout << ret[i] << " ";
  cout << endl;

  delete [] ret;
  
  return 0;
}
