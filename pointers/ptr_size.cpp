// size of pointer
// does it depend on the type of data to which it points?
#include <iostream>
using namespace std;

class Employee
{
  string name;
  int    emp_id;

  public:
  // some functions....
};

int main()
{
  int *int_ptr;
  double *double_ptr;
  Employee *emp_ptr;

  cout << "sizeof(int_ptr)=" << sizeof(int_ptr) << endl;
  cout << "sizeof(double_ptr)=" << sizeof(double_ptr) << endl;
  cout << "sizeof(emp_ptr)=" << sizeof(emp_ptr) << endl;

  return 0;
}
