#include <iostream>
#include <pthread.h>
//#include <thread>
using namespace std;

void* thread_func(void *)
//void thread_func()
{
	cout << "thread_func: executing ..." << endl;
	return nullptr;
}

int main()
{
	//thread t1(thread_func);
	pthread_t id;
	int ret;

	ret = pthread_create(&id, nullptr, thread_func, nullptr);
	if (ret != 0)
	{
		perror("pthread_create");
		exit(1);
	}

	cout << "main thread: executing ..." << endl;

	//t1.join();
	ret = pthread_join(id, nullptr);
	if (ret != 0)
	{
		perror("pthread_join");
		exit(1);
	}
	return 0;
}
