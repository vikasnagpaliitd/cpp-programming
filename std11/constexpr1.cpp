#include <iostream>
using namespace std;

int add(int a, int b) { return a + b; }
constexpr int mult(int a, int b) { return a + b; }

int main()
{
  int arr1[add(10,20)];
  int arr2[mult(10,20)];

  return 0;
}
