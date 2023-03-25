#include <iostream>
using namespace std;

template <typename T>
void print(initializer_list<T> arg)
{
   // one can use begin() and end() too
   for (const auto& elem : arg)
     cout << elem << " ";
   cout << endl;
}


int main()
{
  print({10,20,30});
  print({"a", "b", "c"});
  return 0;
}
