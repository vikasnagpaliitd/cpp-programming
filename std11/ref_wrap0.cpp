#include <iostream>
#include <functional>
using namespace std;
 
int main()
{
  int xyz = 10;
  int& ref = xyz;
  int abc = 12;

  ref = abc;
  ref++;
  cout << "abc = " << abc << endl; // remains 12
  cout << "xyz = " << xyz << endl; // becomes 12+1=13

  cout << "--- with reference wrapper ---" << endl;
  xyz=10;
  abc=12;
  reference_wrapper<int> ref_wrap = xyz;
  ref_wrap = abc;
  ref_wrap++;
  cout << "abc = " << abc << endl; // remains 12
  cout << "xyz = " << xyz << endl; // becomes 12+1=13
  ref_wrap = xyz;
  ref_wrap++;
  cout << "afer switching to xyz and incrementing..." << endl;
  cout << "abc = " << abc << endl; // remains 12
  cout << "xyz = " << xyz << endl; // becomes 12+1=13
  return 0;
}
