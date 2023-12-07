#include"Factory.h"
Factory::Factory()
{
    head = nullptr;
    size = 0;
}

Factory::~Factory()
{
    //dtor
}
void Factory::addQueue()
{
    int s;
    cout << "Enter size of queue: ";cin >> s;
    if (this->head == NULL) {
        this->head = new  QueueNode(s);
        this->head->next = this->head->prev = NULL;
        size++;
       
    }
    else {
        QueueNode* New = new QueueNode(s);
        QueueNode* p = head;
        while (p->next)
            p = p->next;
        p->next = New;
        New->prev = p;

    }

}
int Factory::length()
{
    QueueNode* p = head;
    int count = 0;
    while (p)
    {
        count++;
        p = p->next;

    }
    return count;
}