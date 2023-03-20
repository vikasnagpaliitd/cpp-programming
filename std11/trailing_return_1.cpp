// Mention return type towards end of function declaration
#include <iostream>
using namespace std;

// can be done in declaration
template<typename T, typename U>
auto add(T t, U u) -> decltype(t + u);

// can be done in definition
template<typename T, typename U>
auto add(T t, U u) -> decltype(t + u) {
  return t + u;
}

auto mult(int x, int y) -> int // possible use but unnecessary
{
  return x*y;
}

int main()
{
  cout << "add: " << add(1, 2) << endl;
  cout << "mult: " << mult(1, 2) << endl;

  // can be used in lambda functions
  auto sub_func = [](int x, int y) -> int {return x-y;};
  cout << "sub: " << sub_func(1,2) << endl;

  return 0;
}

