#include"Queue.h"
QueueNode::QueueNode(int init) {
	size = 4;
	NoElment = 0;
	data = new Product * [size];
	this->next = NULL;
	front = rear = 0;
}
void QueueNode::InsertNewProduct() {

	cout << "Select The Product Type : \n\t\t   [1] Milk , \n\t\t   [2] Chips \n                              >>>>> ";
	int c; cin >> c;
	switch (c)
	{
	case 1:
		data[rear] = new Milk;
		data[rear]->SetData();
		data[rear]->AddOpertaion();
		rear++;
		NoElment++;
		break;
	case 2:
		data[rear] = new Chips;	
		data[rear]->SetData();
		data[rear]->AddOpertaion();
		rear++;
		NoElment++;
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
	cout << "REAE = " << rear << "        Size = " << size;
	system("pause");
	return rear == size;
}
bool QueueNode::IsEmpty() {
	return front == rear;
}
void QueueNode::DisplayProducts() {
	for (int i = 0; i < NoElment; i++) {
		cout << NoElment<< "     ";
		//system("pause");
		data[i]->DisplayProductData();
	}
	//system("pause");

}
Product* QueueNode::GetFront() {
	if (IsEmpty()) {
		return NULL;
	}
	return data[front];
}