// Passing arguments to threads
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h> // For semaphores
using namespace std;

//pthread_mutex_t mylock;
sem_t mylock;

// Used to pass arguments
struct argnode
{
	int abc;
	string xyz;
};

void* thread_func(void *arg)
{
	struct argnode *parg = (struct argnode *) arg;
	cout << "thread_func: executing ..." << endl;
	cout << "parg->abc = " << parg->abc << endl;
    for(int i=0;i<10;i++)
    {
		//pthread_mutex_lock(&mylock);
		sem_wait(&mylock);
        parg->xyz += "R";
        //this_thread::sleep_for(100ms);
		usleep(100000);
        parg->xyz += "a";
        parg->xyz += "m";
		//pthread_mutex_unlock(&mylock);
		sem_post(&mylock);
		usleep(100000);
    }

	cout << "after add Ram: parg->xyz = " << parg->xyz << endl;
	return nullptr;
}

int main()
{
	struct argnode
	{
		int abc;
		string xyz;
	} arg = {10,"hello"};

    int ret;
	// Initialize lock 
	//pthread_mutex_init(&mylock, NULL);
	ret = sem_init(&mylock, 0, 1); // semaphore across threads (not processes). initial value 1
    if (ret != 0)
	{
		perror("sem_init");
		exit(1);
	}


	//thread t1(thread_func, abc, ref(xyz));
    pthread_t id;

    ret = pthread_create(&id, nullptr, thread_func, &arg);
    if (ret != 0)
    {
        perror("pthread_create");
        exit(1);
    }

	cout << "main thread: executing ..." << endl;
    for(int i=0;i<10;i++)
    {
		//pthread_mutex_lock(&mylock);
		sem_wait(&mylock);
        arg.xyz += "S";
        //this_thread::sleep_for(100ms);
		usleep(100000); // 100 ms
        arg.xyz += "h";
        arg.xyz += "y";
        arg.xyz += "a";
        arg.xyz += "m";
		//pthread_mutex_unlock(&mylock);
		sem_post(&mylock);
		usleep(100000);
    }


	//t1.join();
    ret = pthread_join(id, nullptr);
    if (ret != 0)
    {
        perror("pthread_join");
        exit(1);
    }

	cout << "main: arg.xyz = " << arg.xyz << endl;

	// Destroy mutex
	//pthread_mutex_destroy(&mylock);
	sem_destroy(&mylock);
	return 0;
}
