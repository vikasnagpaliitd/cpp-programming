#include <iostream>
using namespace std;


auto add(int a, int b) -> int
{
  return a+b;
}

int main()
{
    cout << add(10,20) << endl;
    return 0;
}

