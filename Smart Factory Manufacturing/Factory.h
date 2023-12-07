#ifndef FACTORY_H
#define FACTORY_H
#include<iostream>
#include<string>
#include"Queue.h"
using namespace std;
class Factory
{
private:
    QueueNode* head;
    int size;
public:
    Factory();
    void addQueue();
    int length();

    virtual ~Factory();

protected:

};

#endif // FACTORY_H
