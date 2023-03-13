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
		produced++;
    }

	cout << "producer_func : completed..." << endl;
}


void consumer_func()
{
	cout << "consumer_func : starting..." << endl;

	int product;

	sleep(1);
    //while (! products.empty())
    while (1)
    {
		product_mutex.lock();
		if (! products.empty())
		{
			product = products.back();
			products.pop_back();
			cout << "consumer_func : consumed product " << product << endl;
		}
		product_mutex.unlock();
		sleep_a_little();

    }

	cout << "consumer_func : completed..." << endl;
}

int main()
{
	mutex m1;


	thread producer(producer_func);
	thread consumer(consumer_func);

	cout << "main thread: executing ..." << endl;

	producer.join();
	consumer.join();
	return 0;
}
