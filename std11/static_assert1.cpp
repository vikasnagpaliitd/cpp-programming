// Use of static_assert
#include <iostream>
using namespace std;


//int multiply(int a, int b) // error: non-constant condition for static assertion
constexpr int multiply(int a, int b) // error: non-constant condition for static assertion
{
  return a * b;
}

int main()
{
  static_assert(multiply(5,6)+40 == 70, "Surprise. Calculation error for 70");
  static_assert(multiply(5,6)+40 == 71, "Surprise. Calculation error for 71");

  return 0;
}

