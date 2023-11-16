#include "Queue.h"
using namespace std;
template<class T>
bool Queue<T>::isEmpty() {
	return this->Front == NULL;
}


template<class T>
void Queue<T>::Enqueue(T Value) {
	if (isEmpty()) {
		// is null make front  = last  = the first node
		Front = last = new QNode;
	}
	last->next = new QNode;
}


