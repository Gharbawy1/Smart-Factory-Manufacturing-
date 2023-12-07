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
		data[rear]->AddOpertaion();
		rear = (rear + 1) % size;
		NoElment++;


		break;
	case 2:
		data[rear] = new Chips;
		NoElment++;
		data[rear]->SetData();
		data[rear]->AddOpertaion();
		rear = (rear + 1) % size;
		break;
	}

	cout << "PRODUCT INSERTED SUCSSECFULLY . \n";

}


int QueueNode::RemoveAProduct() {
	if (IsEmpty()) {
		return 0; // mean if returned 0 delete this node cause it became empty
	}
	delete data[front]; // this is pointer no refrence 
	front = (front + 1) % size;
	return 1;// mean removed sucsess
}
int QueueNode::GetNumberOfElments() {
	return this->NoElment;
}
bool QueueNode::IsFull() {
	return (rear + 1) % size == front;
}
bool QueueNode::IsEmpty() {
	return front == rear;
}
void QueueNode::DisplayProducts() {
	for (int i = 0; i < NoElment; i++) {
		data[i]->DisplayProductData();
	}

}