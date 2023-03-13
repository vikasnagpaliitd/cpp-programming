// Passing arguments to threads
#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace std;

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
        parg->xyz += "R";
        //this_thread::sleep_for(100ms);
		usleep(100000);
        parg->xyz += "a";
        parg->xyz += "m";
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
    for(int i=0;i<10;i++)
    {
        arg.xyz += "S";
        //this_thread::sleep_for(100ms);
		usleep(100000); // 100 ms
        arg.xyz += "h";
        arg.xyz += "y";
        arg.xyz += "a";
        arg.xyz += "m";
    }


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
