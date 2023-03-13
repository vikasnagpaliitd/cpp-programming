// Passing arguments to threads
#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace std;

// Used to pass arguments
struct argnode
{
	int abc;
	int xyz;
};

void* thread_func(void *arg)
{
	struct argnode *parg = (struct argnode *) arg;
	cout << "thread_func: executing ..." << endl;
	cout << "parg->abc = " << parg->abc << endl;
	parg->xyz++;
	cout << "after incr: parg->xyz = " << parg->xyz << endl;
	return nullptr;
}

int main()
{
	struct argnode
	{
		int abc;
		int xyz;
	} arg = {10,20};

	//thread t1(thread_func, abc, ref(xyz));
    pthread_t id;
    int ret;

    ret = pthread_create(&id, nullptr, thread_func, &arg);
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

	cout << "main: arg.xyz = " << arg.xyz << endl;
	return 0;
}
