#include <iostream>
#include <type_traits>
using namespace std;

class Point
{
  int x,y;
};
 
int main() 
{
  cout << boolalpha;
  cout << "double: " << is_void<double>::value << '\n';
  cout << "void: " << is_void<void>::value << '\n';
  cout << "Point: " << is_void<Point>::value << '\n';
  cout << "Point: " << is_void_v<Point> << '\n'; // helper. since c++17
  return 0;
}
