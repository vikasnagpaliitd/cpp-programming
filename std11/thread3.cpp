// Passing arguments to threads
#include <iostream>
#include <thread>
using namespace std;

void thread_func(int arg1, int&arg2)
{
	cout << "thread_func: executing ..." << endl;
	cout << "arg1 = " << arg1 << endl;
	arg2++;
	cout << "after incr: arg2 = " << arg2 << endl;
}

int main()
{
	int abc = 10;
	int xyz = 20;
	thread t1(thread_func, abc, ref(xyz));
	cout << "main thread: executing ..." << endl;

	t1.join();
	cout << "main: xyz = " << xyz << endl;
	return 0;
}
