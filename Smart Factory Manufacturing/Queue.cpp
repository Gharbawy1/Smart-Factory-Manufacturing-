#include"Queue.h"

QueueNode::QueueNode(int init) {
	size = init;
	NoElment = 0;
	data = new Product * [size];
	this->next = NULL;
	front = rear = 0;
}


void QueueNode::InsertNewProduct() {
	cout << "Select The Product Type :    [1] Milk , [2] Chips .";
	int c; cin >> c;
	switch (c)
	{
	case 1:
		data[rear] = new Milk;
		data[rear]->SetData();
		NoElment++;
		break;
	case 2:
		data[rear] = new Chips;
		NoElment++;
		data[rear]->SetData();
		break;
	}

}


int QueueNode::GetNumberOfElments() {
	return this->NoElment;
}

