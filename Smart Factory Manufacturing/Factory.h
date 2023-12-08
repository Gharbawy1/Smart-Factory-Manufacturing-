#pragma once
#include"Queue.h"
#include"Stack.h"
const int s = 4;
class Factory {
private:
	int size;
	QueueNode* Head;
	QueueNode* tail;
	int numOfqueue;
public:
	Factory() {
		size = 0;
		Head = tail = NULL;
		numOfqueue = 0;
	}
	
	void AddQueue() {
		if (!HeadExist()) {
			this->Head = new QueueNode(s); // head is current queue
			tail = Head;
			this->Head->next = this->Head->prev = NULL;
			size++;
			numOfqueue++;
		}

		else {
			tail->next = new QueueNode(s);
			tail->next->prev = tail;
			tail = tail->next;
			size++;
			numOfqueue++;
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
			else 
			{
				t->InsertNewProduct();
			}
		}
		else 
		{
			AddQueue();
			Head->InsertNewProduct();
		}
	}

	// Delete Section
	bool IsProductFinished() {
		return Head->GetFront()->GetNumberOfOperations() == 0;
	}
	void DeleteProduct() {
		QueueNode* t = this->Head;
		if (t != NULL) {
			if (IsProductFinished()) {
				t->RemoveAProduct();
			}
			else {
				cout << "This Product Still In Processing \n";
				cout << "Do You Want To Delete All Operations  ?"; char c; cin >> c;
				if (c == 'y') {
					int cnt = t->GetFront()->GetNumberOfOperations();
					while (cnt--)
					{
						DeleteOperationsFromProduct();
					}
					t->RemoveAProduct();
				}
			}
			if (t->IsEmpty()) {
				DeleteFinishedQueue();
			}

			/*if (!t->IsEmpty()) {
				t->RemoveAProduct();
				if (t->IsEmpty()) {
					DeleteFinishedQueue();
				}
			}
			else {
				cout << "Product Not Found.\n";
				return;
			}*/
		}
	}
	void DeleteOperationsFromProduct() {
		QueueNode* t = this->Head;
		if (t != NULL) {
			cout << "This Product still have " << t->GetFront()->GetNumberOfOperations() << "In Progress ";
			cout << "\n > Sure For Deleting ?";
			char c; cin >> c;
			if (c == 'y') {
				t->GetFront()->DeleteOperation();
			}
		}
		else {
			cout << "List Empty\n";
			return;
		}

	}
	void DeleteFinishedQueue() {
		QueueNode* t = this->Head;
			if (t->IsEmpty()) {
				// check to know will delete the head ?
					t->next->prev = NULL;
					Head = t->next;	
					delete t;
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
				cout << "****************************\n";
			}
			t = t->next;
			cout << numOfqueue;
		}
	}
};