#include<iostream>
#include"Proudct.h"
#include"MilkProduct.h"
#include"ChipsProduct.h"
using namespace std;

template<class T>
class QueueBasedArray {
private:
	int rear; 
	int front;
	T** arr;
	int size; int NoElmentes;
public:
	QueueBasedArray(int init = 3);
	void Enqueue();
	void Dequeue();





};


