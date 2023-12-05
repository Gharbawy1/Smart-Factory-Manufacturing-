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
    virtual ~Stack();

protected:

};

#endif // STACK_H
