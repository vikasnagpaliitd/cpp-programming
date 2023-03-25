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

  cout << "ref_wrapper address=" <<&ref_wrap << endl;
  cout << "abc address=" <<&abc<< endl;


  ref_wrap++;
  cout << "abc = " << abc << endl; // 13
  cout << "xyz = " << xyz << endl; // 10
  ref_wrap = xyz;
  ref_wrap++;
  cout << "afer switching to xyz and incrementing..." << endl;
  cout << "abc = " << abc << endl; // 13
  cout << "xyz = " << xyz << endl; // 11
  return 0;
}
