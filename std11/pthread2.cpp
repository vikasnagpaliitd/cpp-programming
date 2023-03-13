#include <iostream>
#include <pthread.h>
#include <unistd.h> // Note : for different Linux functions
//#include <thread>
using namespace std;

void* thread_func(void *)
//void thread_func()
{
	int ret;

    for(int i=0;i<10;i++)
    {
        //this_thread::sleep_for(1000ms); // Note: this_thread
        //usleep(1000000); // 1 sec
        sleep(1); // 1 sec

        //this_thread::yield(); // Friendly gesture to allow other threads
		ret = pthread_yield();
		if (ret != 0) // Note : 0 vs non-zero
			perror("pthread_yield");
        cout << "thread_func: executing ..." << endl;
    }

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

    for(int i=0;i<10;i++)
    {
        //this_thread::sleep_for(1000ms); // Note: this_thread
        usleep(1000000); // 1 sec

        //this_thread::yield(); // Friendly gesture to allow other threads
		ret = pthread_yield();
		if (ret != 0)
			perror("pthread_yield");
        cout << "main thread: executing ..." << endl;
    }

	//t1.join();
	ret = pthread_join(id, nullptr);
	if (ret != 0)
	{
		perror("pthread_join");
		exit(1);
	}
	return 0;
}
