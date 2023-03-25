#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
using namespace std;

//unsigned long int count = 0;
//atomic<unsigned long int> count = 0; //doesnt work
//atomic<unsigned long int> count(0); 
//atomic<unsigned long int> count{0}; 
atomic_ulong count(0);
mutex m;

void incr(unsigned int N)
{
  for(unsigned int i=0;i<N;i++)
    count ++;
}

void mutex_incr(unsigned int N)
{
  for(unsigned int i=0;i<N;i++)
  {
    lock_guard<mutex> lg(m);
    count ++;
  }
}

void atomic_incr(unsigned int N)
{
  for(unsigned int i=0;i<N;i++)
    count ++; // count to be made atomic<unsiged long>
    //count = count + 1; // not safe. atomic read + atomic write != atomic
   //count *= 2; // does not compile as multiply not atomic
}

int main()
{
  unsigned int N = 100000;
  //thread t1(mutex_incr, N);
  //thread t2(mutex_incr, N);
  //thread t1(incr, N);
  //thread t2(incr, N);
  thread t1(atomic_incr, N);
  thread t2(atomic_incr, N);

  t1.join();
  t2.join();
  cout << "counting " << N << " times twice = " << count << endl;

  return 0;
}
