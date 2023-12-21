#ifndef STACK_H
#define STACK_H
#include<iostream>
#include"Operation.h"
using namespace std;

class Stack
{
private:
    int top;
    int size;
    Operation** arr;

public:
    Stack();
    Stack(int size);

    void push(Operation* op);
    Operation* pop();
    Operation* stackTop();
    void displayOperations();
    bool IsEmpty();
    bool IsFull();
    virtual ~Stack();
    Operation* operator[](int index) {
        return arr[index];
    }
protected:

};


#endif // STACK_H
