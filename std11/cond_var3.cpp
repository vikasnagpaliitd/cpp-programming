// Condition Variables
#include <iostream>
#include <thread>
#include <mutex>
#include <random>
#include <chrono>
#include <unistd.h>
#include <condition_variable>
using namespace std;

const int NUM_PRODUCTS = 20;

vector<int> products;
mutex product_mutex;
condition_variable product_produced_condition;


void sleep_a_little()
{
    std::mt19937_64 eng{std::random_device{}()};
    std::uniform_int_distribution<> dist{10, 100};
    std::this_thread::sleep_for(std::chrono::milliseconds{dist(eng)});
}

void producer_func()
{
	cout << "producer_func : starting..." << endl;

	int produced = 0;

    while (produced < NUM_PRODUCTS)
    {
				sleep_a_little();
				product_mutex.lock(); // lock_guard would be a better idea
				products.push_back(produced);
				product_mutex.unlock();
				product_produced_condition.notify_one();
				produced++;
    }

	cout << "producer_func : completed..." << endl;
}


void consumer_func()
{
	cout << "consumer_func : starting..." << endl;

	int product;

	//Note:Removed all sleep in client
	//sleep(1);
    //while (! products.empty())
    while (1)
    {
				unique_lock<mutex> lock(product_mutex);
				product_produced_condition.wait(lock);
				// Note: when we come here, we hold the mutex locked
				if (! products.empty())
				{
					product = products.back();
					products.pop_back();
					cout << "consumer_func : consumed product " << product << endl;
				}
				else
					cout << "consumer_func : spurious wakeup" << endl;
				//product_mutex.unlock();
				//sleep_a_little();

    } // mutex lock is released here after each iteration

	cout << "consumer_func : completed..." << endl;
}

int main()
{

	thread producer(producer_func);
	thread consumer(consumer_func);

	cout << "main thread: executing ..." << endl;

	producer.join();
	consumer.join();
	return 0;
}
