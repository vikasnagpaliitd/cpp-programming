#include <iostream>
using namespace std;


template<typename T, typename U>
//auto add(T a, U b) -> decltype(a+b)
decltype(10+20.1) add(T a, U b)
{
  decltype(a+b) c;
  c=a+b;
  //return a+b;
  return c;
}

int main()
{
    cout << add(10.1,20) << endl;
    return 0;
}

