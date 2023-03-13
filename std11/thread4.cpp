// Problem in concurrency
#include <iostream>
#include <thread>
using namespace std;

void thread_func(int arg1, string&arg2)
{
	cout << "thread_func: executing ..." << endl;
	for(int i=0;i<10;i++)
	{
		arg2 += "R";
		this_thread::sleep_for(200ms);
		arg2 += "a";
		arg2 += "m";
	}
	cout << "thread_func:after incr: arg2 = " << arg2 << endl;
}

int main()
{
	int abc = 10;
	string xyz = "hello";
	thread t1(thread_func, abc, ref(xyz));
	cout << "main thread: executing ..." << endl;
	for(int i=0;i<10;i++)
	{
		xyz += "S";
		this_thread::sleep_for(100ms);
		xyz += "h";
		xyz += "y";
		xyz += "a";
		xyz += "m";
	}

	t1.join();
	cout << "main: xyz = " << xyz << endl;
	return 0;
}
