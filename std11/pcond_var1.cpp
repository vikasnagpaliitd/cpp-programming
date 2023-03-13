// Condition Variables
#include <iostream>
//#include <thread>
//#include <mutex>
#include <pthread.h>
#include <random>
#include <chrono>
#include <unistd.h>
using namespace std;

const int NUM_PRODUCTS = 20;

vector<int> products;


void sleep_a_little()
{
    std::mt19937_64 eng{std::random_device{}()};
    std::uniform_int_distribution<> dist{10, 100};
    std::this_thread::sleep_for(std::chrono::milliseconds{dist(eng)});
}

void* producer_func(void *)
{
	cout << "producer_func : starting..." << endl;

	int produced = 0;

    while (produced < NUM_PRODUCTS)
    {
       sleep_a_little();

       products.push_back(produced);
       produced++;
    }

	cout << "producer_func : completed..." << endl;
}


void consumer_func(void *)
{
	cout << "consumer_func : starting..." << endl;

	int product;

	sleep(1);
    while (! products.empty())
    {
       sleep_a_little();
	   product = products.back();
	   products.pop_back();
       cout << "consumer_func : consumed product " << product << endl;

    }

	cout << "consumer_func : completed..." << endl;
}

int main()
{

	pthread_t producer_tid;
	pthread_t consumer_tid;

	//thread producer(producer_func);
	//thread consumer(consumer_func);

    ret = pthread_create(&producer_tid, nullptr, producer_func, nullptr);
    if (ret != 0)
    {
        perror("pthread_create");
        exit(1);
    }

    ret = pthread_create(&consumer_tid, nullptr, consumer_func, nullptr);
    if (ret != 0)
    {
        perror("pthread_create");
        exit(1);
    }


	cout << "main thread: executing ..." << endl;


    ret = pthread_join(producer_tid, nullptr);
    if (ret != 0)
    {
        perror("pthread_join");
        exit(1);
    }
    ret = pthread_join(consumer_tid, nullptr);
    if (ret != 0)
    {
        perror("pthread_join");
        exit(1);
    }

	producer.join();
	consumer.join();
	return 0;
}
