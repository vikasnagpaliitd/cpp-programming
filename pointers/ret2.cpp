// It it wrong to return address of local variables?
//  what about address of local static variables?

#include <iostream>
using namespace std;
#define MAX_ELEM 20

// Return array having 1st 'n' natural numbers
int* get_natural_num_list(int n)
{
   //int arr[MAX_ELEM];
   static int arr[MAX_ELEM];
   int i;

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
  
  return 0;
}
