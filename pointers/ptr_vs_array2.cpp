// When we pass an array to a function, it degenerates to a pointer
#include <iostream>
using namespace std;

//void func(int arr[100])
//void func(int arr[])
void func(int *arr)
{
  cout <<" Inside func: sizeof(arr)=" << sizeof(arr) << endl;
  cout << "arr[0]=" << arr[0] << endl;
  arr++;
  cout << "after increment:\narr[0]=" << arr[0] << endl;
}

int main()
{
  
  int arr[100] = {10,20,30,40,50};
  cout <<" Inside main: sizeof(arr)=" << sizeof(arr) << endl;
  func(arr);

  return 0;

}
