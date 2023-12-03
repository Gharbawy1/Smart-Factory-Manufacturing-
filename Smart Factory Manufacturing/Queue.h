#pragma once
#include<iostream>
#include"Stack.h"
using namespace std;
template<class T>
// enque(&stack)
struct QNode
{
	Stack<T>* stack;
	QNode* next;

};
template<class T>
class Queue
{
private:
	QNode<T>* Front;
	QNode<T>* last;

public:
	bool isEmpty();
	void Enqueue(T value);
	void Dequeue();







};

