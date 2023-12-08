#pragma once
#include"Queue.h"
#include"Stack.h"
#include"Proudct.h"
#include<vector>

const int s = 4;
class Factory {
private:
	int size;
	QueueNode* Head;
	QueueNode* tail;
public:
	//vector<Product*> FinishedProduct;
	Product** arr;  
	int FinishedCounter;
	Factory() {
		size = 0;
		Head = tail = NULL;
		FinishedCounter = 0;
		//arr = new Product[5];
	}
	
	void AddQueue() {
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
	void ManageDeletion() {
		cout << "\n\t\t\t\t\t\t    ---------------------- ";
		cout << "\n\t\t\t\t\t\t =>|  Operations Manager  |";
		cout << "\n\t\t\t\t\t\t    ---------------------- \n\n";
		QueueNode* t = this->Head;
		cout << "    ==> Finish \n         [1] Operation By Operation . \n         [2] Finish All Operations. \n\n \t\t\t >"; int c; cin >> c;
		switch (c)
		{
		case 1:
			FinishOneOperatoin();
			break;
		case 2:
			DeleteProduct();
			break;
		}

	
	}


	void DeleteProduct() {
		QueueNode* t = this->Head;
		if (t != NULL) {
			if (IsProductFinished()) {
				t->RemoveAProduct();
			}
			else {	
						DeleteAllOperationsFromProduct();
						//FinishedProduct.push_back(t->GetFront());
						//arr[FinishedCounter++] = t->GetFront();
						t->RemoveAProduct();
			}
			if (t->IsEmpty()) {
				DeleteFinishedQueue();
			}

			
		}
	}
	void FinishOneOperatoin() {
		QueueNode* t = this->Head;
		if (t != NULL) {
			if (!t->IsEmpty()) {
				t->GetFront()->DeleteOperation();
				if (t->GetFront()->GetNumberOfOperations() == 0) {
					// delete the product (stack is empty)4
					//FinishedProduct.push_back(t->GetFront());
					//arr[FinishedCounter++] = t->GetFront();

					t->RemoveAProduct();
				}
			}
			
		}
	}
	void DeleteAllOperationsFromProduct() {
		QueueNode* t = this->Head;
		if (t != NULL) {
			cout << "This Product still have " << t->GetFront()->GetNumberOfOperations() << " Operaions In Progress ";
			cout << "\n > Sure For Finish All these operations ?";
			char c; cin >> c;
			if (c == 'y') {
				int cnt = t->GetFront()->GetNumberOfOperations();
				while (cnt--)
				{
					t->GetFront()->DeleteOperation();
				}
				//t->GetFront()->UpdateState(1);
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
			if (t->next){
				t->next->prev = NULL;
			}
				Head =Head->next;
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
		}
	}
	void DisplayedFinishedProducts() {
		for (int i = 0; i < FinishedCounter; i++) {
			//arr[i]->DisplayProductData();
		}
	}
};