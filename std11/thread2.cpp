// The threads execute concurrently
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void thread_func()
{
	for(int i=0;i<10;i++)
	{
		this_thread::sleep_for(1000ms); // Note: this_thread
		//this_thread::yield(); // Friendly gesture to allow other threads
		cout << "thread_func: executing ..." << endl;
	}
}

int main()
{
	thread t1(thread_func);
	for(int i=0;i<10;i++)
	{
		this_thread::sleep_for(1000ms);
		//this_thread::yield(); // Friendly gesture to allow other threads
		cout << "main thread: executing ..." << endl;
	}

	t1.join();
	return 0;
}
