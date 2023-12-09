#include"Queue.h"
int QueueNode::NumOfFinishedMilkProducts = 0;
int  QueueNode::NumOfFinishedChipsProducts = 0;
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


void QueueNode::RemoveAProduct() {
	if (IsEmpty()) {
		cout << "Empty Queue Cant Delete . ";
		return ; // mean if returned 0 delete this node cause it became empty
	}
	//delete data[front]; // this is pointer no refrence 
	//front = (front + 1) % size;
	front++;
	
	NoElment--;
	return;
}
int QueueNode::GetNumberOfElments() {
	return this->NoElment;
}
bool QueueNode::IsFull() {
	
	return rear == size;
}
bool QueueNode::IsEmpty() {
	return front == rear;
}
void QueueNode::DisplayProducts() {
	for (int i = front; i < rear; i++) {
		
		//system("pause");
		data[i]->DisplayProductData();
	}
	//system("pause");

}
int QueueNode::GetNumOfChipsProducts()
{
	return NumOfFinishedChipsProducts;
}
Product* QueueNode::GetFront() {
	if (IsEmpty()) {
		return NULL;
	}
	return data[front];
}

void  QueueNode::CalcProducts() {
	for (int i = 0; i < size; ++i) {
		if (Chips* chips = dynamic_cast<Chips*>(data[i])) {
			NumOfFinishedChipsProducts++;
		}
		else if (Milk* milk = dynamic_cast<Milk*>(data[i])) {
			NumOfFinishedMilkProducts++;
		}
	}
}

int QueueNode::GetNumOfMilkProducts()
{
	return NumOfFinishedMilkProducts;
}
