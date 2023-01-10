#include <iostream>
using namespace std;

template <class T>
class MySequence
{
	T *arr;
	int size;
	int capacity;

public:
	MySequence(int acapacity, int asize, T def_val , T step_size) : capacity(acapacity), size(asize)
	{
		T val = def_val;
		arr =  new T[capacity];
		for(int i = 0;i < size; i++)
		{
			arr[i] = val;
			val = val + step_size;
		}
	}


	~MySequence()
	{
		delete [] arr;
	}


};


int main()
{

	MySequence<int> intseq(100, 10, 20, 1);
	MySequence<string> strseq(200, 20, "abc", "a");

	return 0;
}
