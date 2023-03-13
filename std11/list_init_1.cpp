#include <iostream>
using namespace std;

struct node
{
 int a;
 struct subnode
 {
   int b;
   int c;
 } sub;
};

int main()
{

  //struct node s1 = {10,20,30};
  //struct node s1 = {10,{20,30}};
  struct node s1 = {.sub.b=10,.sub.c=20,.a=30};
  cout << s1.a << " " << s1.sub.b << " " << s1.sub.c << endl;

    return 0;
}

