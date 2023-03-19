// decltype also returns value category (e.g. lvalue/rvalue reference)
// Use of static_assert
#include <iostream>
#include <typeinfo>
using namespace std;




int main()
{
  int x = 10;
  const int& lvalue_ref_const = x;
  int&& rvalue_ref = 20;

  static_assert(std::is_same<decltype(x), int>::value);
  static_assert(std::is_same<int&, int&>::value);
  static_assert(std::is_same<decltype(rvalue_ref), int&&>::value);
  static_assert(std::is_same<decltype(lvalue_ref_const), const int&>::value);
  static_assert(std::is_same<decltype(x+5), int>::value);
  static_assert(std::is_same<decltype((x)), int&>::value);
  //cout << typeid(x+5).name() << endl;
  //static_assert(std::is_same<decltype(add(1,2)), float>::value);
  //static_assert(std::is_same<decltype(add(1,2)), float>::value, "Custom Error Message");


  return 0;
}

