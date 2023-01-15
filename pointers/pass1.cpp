// Wrong attempt to increment an integer passed to a function
#include <iostream>
using namespace std;

void increment(int arg)
{
   arg++;
}

int main()
{
  int xyz = 10;
  cout<<"Before increment: xyz=" << xyz << endl;
  increment(xyz);
  cout<<"After increment: xyz=" << xyz << endl;
  
  return 0;
}
