#include"QueueBasedArray.h"



template<class T>
QueueBasedArray<T>::QueueBasedArray(int init = 3)
{
	size = init;
	front = rear = 0;
	arr = new T * [size];
	NoElmentes = 0;
}

template<class T>
void QueueBasedArray<T>::Enqueue()
{
		if (isFull()) {
			throw std::runtime_error("Queue overflow!");
		}
		// first spisify the type


		arr[rear] = new ;
		rear = (rear + 1) % CAPACITY;
}