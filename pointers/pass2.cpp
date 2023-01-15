// If we want int to change, pass int*
#include <iostream>
using namespace std;

// If we wish some data to get modified, we can pass its pointer
void increment(int *p_arg)
{
  //*p_arg++;// would be wrong due to operator precedence
  (*p_arg)++;
}

int main()
{
  int xyz = 10;
  cout<<"Before increment: xyz=" << xyz << endl;
  increment(&xyz);
  cout<<"After increment: xyz=" << xyz << endl;
  
  return 0;
}
