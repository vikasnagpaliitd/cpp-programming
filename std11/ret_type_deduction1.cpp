#include <iostream>
using namespace std;

auto add(int a, int b) { return a+b;} 

auto func(int c, string d) { 
if (c) return c; 
else return d;
}

int main()
{
  cout << add(10,20) << endl;
  return 0;
}
