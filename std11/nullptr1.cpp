#include <iostream>
using namespace std;

void foo(char* str)
{
  cout << "foo(str) " << str << endl;
}

void foo(int i)
{
  cout << "foo(int) " << i << endl;
}

int main()
{
  //foo(NULL);
  foo(nullptr);
  return 0;
}

