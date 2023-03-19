// Use decltype to mean the type of an expression
// Use of static_assert
#include <iostream>
#include <typeinfo>
using namespace std;

template<typename T, typename U>
auto add(T t, U u) -> decltype(t + u) {
  return t + u;
}

int main()
{
  cout << add(1, 2) << " ";
  cout << typeid(decltype(add(1, 2))).name() << endl;
  //static_assert(std::is_same<decltype(add(1,2)), int>::value);
  //static_assert(std::is_same<decltype(add(1,2)), float>::value);
  //static_assert(std::is_same<decltype(add(1,2)), float>::value, "Custom Error Message");

  cout << add(1.2, 2) << " ";
  cout << typeid(add(1.2, 2)).name() << endl;

  cout << add(string("hello"), string("world")) << " ";
  cout << typeid(add(string("hello"), string("world"))).name() << endl;

  return 0;
}

