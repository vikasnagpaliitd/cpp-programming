// Multiple consumers
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
		product_mutex.lock();
		products.push_back(produced);
		product_mutex.unlock();
		//product_produced_condition.notify_one();
		product_produced_condition.notify_all();
		produced++;
    }

	cout << "producer_func : completed..." << endl;
}


void consumer_func(int id)
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
			cout << "consumer_func " << id << " : consumed product " << product << endl;
		}
		else
			cout << "consumer_func " << id << " : spurious wakeup" << endl;
		//product_mutex.unlock();
		//sleep_a_little();

    }

	cout << "consumer_func : completed..." << endl;
}

int main()
{

	thread producer(producer_func);
	thread consumer1(consumer_func, 1);
	thread consumer2(consumer_func, 2);
	thread consumer3(consumer_func, 3);

	cout << "main thread: executing ..." << endl;

	producer.join();
	consumer1.join();
	consumer2.join();
	consumer3.join();
	return 0;
}
