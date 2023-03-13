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
pthread_mutex_t product_mutex;
pthread_cond_t product_produced_condition;


void sleep_a_little()
{
    std::mt19937_64 eng{std::random_device{}()};
    std::uniform_int_distribution<> dist{10, 100};
    //std::this_thread::sleep_for(std::chrono::milliseconds{dist(eng)});
	usleep(dist(eng) * 1000);
}

void* producer_func(void *)
{
	cout << "producer_func : starting..." << endl;

	int produced = 0;

    while (produced < NUM_PRODUCTS)
    {
		sleep_a_little();
		pthread_mutex_lock(&product_mutex);
		products.push_back(produced);
		pthread_mutex_unlock(&product_mutex);
		//product_produced_condition.notify_one();
		pthread_cond_signal(&product_produced_condition);
		produced++;
    }

	cout << "producer_func : completed..." << endl;
	return nullptr;
}


void* consumer_func(void *)
{
	cout << "consumer_func : starting..." << endl;

	int product;

    //while (! products.empty())
    while (1)
    {
        //product_mutex.lock();
		pthread_mutex_lock(&product_mutex);
		//product_produced_condition.wait(lock);
		pthread_cond_wait(&product_produced_condition, &product_mutex);
        if (! products.empty())
        {
            product = products.back();
            products.pop_back();
            cout << "consumer_func : consumed product " << product << endl;
        }
		else
			cout << "consumer_func : spurious wakeup" << endl;
		pthread_mutex_unlock(&product_mutex);
        //sleep_a_little(); // Note: removed sleep in client
    }

	cout << "consumer_func : completed..." << endl;
	return nullptr;
}

int main()
{

	pthread_t producer_tid;
	pthread_t consumer_tid;
	int ret;

    // Initialize mutex
    pthread_mutex_init(&product_mutex, NULL);
    // Initialize mutex
    pthread_cond_init(&product_produced_condition, NULL);


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


	//producer.join();
	//consumer.join();
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


    // Destroy mutex
    pthread_mutex_destroy(&product_mutex);
	// Destroy condition
    pthread_cond_init(&product_produced_condition, NULL);
	return 0;
}
