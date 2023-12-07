#pragma once
#include"Queue.h"
class Factory {
private:
	int size;
	QueueNode* Head;
	QueueNode* tail;
public:
	Factory() {
		size = 0;
		Head = tail = NULL;
	}
	void AddQueue() {
		int s; cout << "> Please enter the size of Queue : "; cin >> s;
		if (!HeadExist()) {
			this->Head = new QueueNode(s); // head is current queue
			tail = Head;
			this->Head->next = this->Head->prev = NULL;
			size++;

		}

		else {
			tail->next = new QueueNode(s);
			tail->next->prev = tail;
			tail = tail->next;
			size++;
		}
	}
	int GetLength();

	void PushInSuitable() {
		QueueNode* t = this->tail;
		if (Head) {
			if (t->IsFull()) {
				// create new Node " No Space for next product"
				AddQueue();
				
				tail->InsertNewProduct();
			}
			else {
				t->InsertNewProduct();
			}
		}
		else {
			AddQueue();
			
			Head->InsertNewProduct();
		}
	}
	void DeleteFinishedQueue() {
		QueueNode* t = this->Head;
		QueueNode* curr = t;
		bool IsDeleted = false;
		while (t)
		{
			if (t->IsEmpty()) {
				if (t == Head) {
					t->next->prev = NULL;
					Head = t->next;
					curr = Head;
					delete t;

				}
				else {
					t->prev->next = t->next;
					if (t->next) {
						t->next->prev = t->prev;
					}
					curr = t->next;
					delete t;
				}
			}
			else {
				curr = t->next;
			}
			t = curr;
			

		}
	}

	bool HeadExist() {
		return Head != NULL;

	}
	void DisplayProducts() {
		QueueNode* t = this->Head;
		while (t)
		{
			t->DisplayProducts();
			if (t->next) {
				cout << "****************************";
			}
			t = t->next;
		}
	}
};