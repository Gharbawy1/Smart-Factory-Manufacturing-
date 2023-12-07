#include"Factory.h"

Factory::Factory() {
	size = 0;
	Head = tail = NULL;
}

void Factory::AddQueue() {
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

bool Factory::HeadExist() {
	return Head != NULL;
}

void Factory::PushInSuitable() {
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

void Factory::DisplayProducts() {
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