// Concurrency problem solved using mutex : lock_guard
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

void thread_func(int arg1, string&arg2, mutex& m1)
{
	cout << "thread_func: executing ..." << endl;
	for(int i=0;i<10;i++)
	{
		{
				lock_guard<mutex> lock1(m1);
				//m1.lock();
				arg2 += "R";
				this_thread::sleep_for(200ms);
				arg2 += "a";
				arg2 += "m";
				//m1.unlock();
		}
		this_thread::sleep_for(200ms); // Just to give other thread a chance
	}
	cout << "thread_func:after incr: arg2 = " << arg2 << endl;
}

int main()
{
	mutex m1;


	int abc = 10;
	string xyz = "hello";
	thread t1(thread_func, abc, ref(xyz), ref(m1));
	cout << "main thread: executing ..." << endl;
	for(int i=0;i<10;i++)
	{
    {
  		lock_guard<mutex> lock1(m1);
  		//m1.lock();
  		xyz += "S";
  		this_thread::sleep_for(100ms);
  		xyz += "h";
  		xyz += "y";
  		xyz += "a";
  		xyz += "m";
  		//m1.unlock();
    }
		this_thread::sleep_for(200ms); // Just to give other thread a chance
	}

	t1.join();
	cout << "main: xyz = " << xyz << endl;
	return 0;
}
