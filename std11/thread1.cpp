#include <iostream>
#include <thread>
using namespace std;

void thread_func()
{
	cout << "thread_func: executing ..." << endl;
}

int main()
{
	thread t1(thread_func);
	cout << "main thread: executing ..." << endl;

	t1.join();
	return 0;
}
