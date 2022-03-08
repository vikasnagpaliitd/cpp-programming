// Copyright: Vikas Nagpal (Anuttara Learning)
#include <iostream>
#include <assert.h>
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

	class iterator
	{
		int index;
		MySequence<T> *container;
		public:

		iterator(MySequence<T> *acontainer, int val=0) : container(acontainer), index(val)
		{
		}

		T& operator*()
		{
			assert((index>=0) && (index<container->size));
			return container->arr[index];
		}
	};


	iterator begin()
	{
		return iterator(this, 0);
	}
	iterator end()
	{
		return iterator(this, size);
	}

};


int main()
{

	MySequence<int> intseq(100, 10, 20, 1);
	MySequence<string> strseq(200, 20, "abc", "a");

	MySequence<int>::iterator intseq_itr = intseq.begin();
	cout << "*intseq_itr = " << *intseq_itr << endl;


	auto strseq_itr = strseq.begin();
	cout << "*strseq_itr = " << *strseq_itr << endl;


	return 0;
}
