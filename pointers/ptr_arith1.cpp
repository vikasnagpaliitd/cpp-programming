#include <iostream>

using namespace std;
#define MAX_LEN 20

int main()
{
  int int_array[MAX_LEN] = {10,20,30};
  double double_array[MAX_LEN] = {1.1, 1.2, 1.3};
 
  int *int_ptr = int_array;
  double *double_ptr = double_array;
 
  cout << "int_ptr=" << int_ptr << endl;
  cout << "double_ptr=" << double_ptr << endl;

  int_ptr++;
  double_ptr++;
  cout << "After incrementing both pointers..." << endl;

  cout << "int_ptr=" << int_ptr << endl;
  cout << "double_ptr=" << double_ptr << endl; 

  cout << "Sizes of int and double are..." << endl;

  cout << "sizeof(int)=" << sizeof(int) << endl;
  cout << "sizeof(double)=" << sizeof(double) << endl; 
  return 0;
}
