// Copyright: Vikas Nagpal (Anuttara Learning)
#include <iostream>
using namespace std;

class Point
{

};

class PointFactory {

   private:
   static PointFactory *instance;
   // vector<Point *> pointPool;
 
   // Private constructor so that no objects can be created.
   PointFactory() {
      // Initialize Pool
   }

   public:
   static PointFactory *getInstance() {
      if (!instance)
      {
          cout << "getInstance() creating PointFactory object" << endl;
          instance = new PointFactory;
      }
      cout << "getInstance() returning PointFactory object pointer" << endl;
      return instance;
   }

   Point* allocPoint()
   {
      // allocate Point object from pointPool
      return nullptr;
   }

   void deallocPoint(Point *ptr)
   {
      // deallocate Point into pointPool
   }

};

PointFactory* PointFactory::instance = nullptr;

int main()
{
    PointFactory *p1 = PointFactory::getInstance();
    PointFactory *p2 = PointFactory::getInstance();
}
