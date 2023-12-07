#include "Stack.h"

Stack::Stack()
{
    size = 5;
    arr = new Operation * [size];
    top = -1;
}

Stack::~Stack()
{
    for (int i = 0; i <= top; i++)
        delete[]arr[i];
    delete[]arr;
}
Stack::Stack(int size)
{
    this->size = size;
    arr = new Operation * [size];
    top = -1;


}
void Stack::push(Operation* op)
{
    if (top == size - 1)
    {
        cout << "Stack is full\n";
        return;
    }
    arr[++top] = op; 

}
Operation* Stack::pop()
{
    if (top == -1) {
        cout << "Stack is empty\n";
        return nullptr;
    }
    return arr[top--];

}
Operation* Stack::stackTop()
{
    if (top == -1) {
        cout << "Stack is empty\n";
        return nullptr;
    }
    return arr[top]; 

}
void Stack::displayOperations()
{
    if (top == -1)
        cout << "Stack is empty\n";
    else
    {
        for (int i = top;i >= 0;i--)
            cout << *arr[i];

    }

}

bool Stack::IsEmpty() {
    return top == -1;
}
bool Stack::IsFull() {
    return top == size - 1;
}
