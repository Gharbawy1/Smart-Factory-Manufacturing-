#include"Queue.h"
#include<Windows.h>
//int QueueNode::NumOfMilkProducts = 0;
//int  QueueNode::NumOfChipsProducts = 0;
const int DEFAULT_COLOR = 7; // White
const int HIGHLIGHT_COLOR = 10; // Green
void setConsoleColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void drawMenu(int option) {
	system("cls"); 

	cout << "Select The Product Type:\n";
	for (int i = 1; i <= 2; ++i) {
		if (i == option) {
			setConsoleColor(HIGHLIGHT_COLOR);
			cout << "\t\t-> [" << i << "]  ";
		}
		else {
			setConsoleColor(DEFAULT_COLOR);
			cout << "\t\t[" << i << "] ";
		}

		switch (i) {
		case 1:
			cout << "Milk ";
			break;
		case 2:
			cout << "Chips ";
			break;
		
		}
		cout << "\n";
	}
	setConsoleColor(DEFAULT_COLOR);
}
QueueNode::QueueNode(int init) {
	size = 4;
	NoElment = 0;
	data = new Product * [size];
	this->next = NULL;
	front = rear = 0;
	//NumOfMilkProducts = 0;
	//NumOfChipsProducts = 0;
	
}
void QueueNode::InsertNewProduct() {

	int option = 1;
	while (true) {
		drawMenu(option);
		char key = _getch();


		if (key == '\r') { // Enter key pressed

			switch (option) {
			case 1:
				cout << endl << endl << "\t";
				data[rear] = new Milk;
				data[rear]->SetData();
				data[rear]->AddOpertaion();
				rear++;
				NoElment++;
				break;
			case 2:
				cout << endl << endl << "\t";
				data[rear] = new Chips;
				data[rear]->SetData();
				data[rear]->AddOpertaion();
				rear++;
				NoElment++;
				break;
			}
			cout << "PRODUCT INSERTED SUCCESSFULLY.\n";
			break;
		}
		else if (key == 27) { // Escape key pressed
			cout << "Selection canceled.\n";
			break;
		}
		else if (key == 72 && option > 1) { // Up arrow 
			option--;
		}
		else if (key == 80 && option < 2) { // Down arrow
			option++;
		}
	}

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



Product* QueueNode::GetFront() {
	if (IsEmpty()) {
		return NULL;
	}
	return data[front];
}




//void  QueueNode::CalcProducts() {
//	
//	for (int i = 0; i < NoElment; ++i) {
//		if (Chips* chips = dynamic_cast<Chips*>(data[i])) {
//			//chips->describe();
//			NumOfChipsProducts++;
//		}
//		else if (Milk* milk = dynamic_cast<Milk*>(data[i])) {
//			//milk->describe();
//			NumOfMilkProducts++;
//		}
//	}
//	
//}
//int QueueNode::GetNumOfChipsProducts()
//{
//	return NumOfChipsProducts;
//}
//
//int QueueNode::GetNumOfMilkProducts()
//{
//	return NumOfMilkProducts;
//}
