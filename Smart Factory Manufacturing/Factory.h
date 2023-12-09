#pragma once
#include"Queue.h"
#include"Stack.h"
#include"Proudct.h"
#include<vector>
#include<algorithm>
const int s = 4;
class Factory {
private:
	int size;
	QueueNode* Head;
	QueueNode* tail;
	int NumOfFinishMilkProducts;
	int NumOfFinishChipsProducts;
	int NumOfAllProducts;
public:
	Product** FinishedProducts;
	int FinishedCounter;
	Factory() {
		size = 0;
		Head = tail = NULL;
		FinishedCounter = 0;
		FinishedProducts = new Product * [10];
		NumOfFinishMilkProducts = 0; NumOfFinishChipsProducts = 0; NumOfAllProducts = 0;
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
				NumOfAllProducts++;
			}
			else 
			{
				t->InsertNewProduct();
				NumOfAllProducts++;
			}
		}
		else 
		{
			AddQueue();
			Head->InsertNewProduct();
			NumOfAllProducts++;
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
						FinishedProducts[FinishedCounter++] = t->GetFront();
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
					FinishedProducts[FinishedCounter++] = t->GetFront();
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
		cout << " >> We Have " << abs(NumOfAllProducts - FinishedCounter) << " Product In This Factory In Procissing \n\n";
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
		cout << "> We Have " << FinishedCounter << " Finished Product Sucsessfully\n\n";
		int FInishedmilkfound = 0;

		cout << " ======== Finished Milk Products ======== \n\n";
		for (int i = 0; i < FinishedCounter; i++) {
			 if (Milk* milk = dynamic_cast<Milk*>(FinishedProducts[i])) {
				 FinishedProducts[i]->DisplayProductData(); FInishedmilkfound = 1;
			}
		}
		if (FInishedmilkfound == 0) {
			cout << "=> There are no Finished Milk products Untill Now \n\n";
		}
		cout << " ======== Finished Chips Products ======== \n\n";
		int FInishedChipsfound = 0;
		for (int i = 0; i < FinishedCounter; i++) {
			if (Chips* chips = dynamic_cast<Chips*>(FinishedProducts[i])) {
				FinishedProducts[i]->DisplayProductData();
				FInishedChipsfound = 1;
			}
		}
		if (FInishedChipsfound == 0) {
			cout << "=> There are no Finished Chips products Untill Now \n\n";
		}

	}
	void DisplayNumOfFinishedProducts() {
		this->NumOfFinishMilkProducts = 0;
		this->NumOfFinishChipsProducts = 0;
		for (int i = 0; i < FinishedCounter; i++) {
			if (Chips* chips = dynamic_cast<Chips*>(FinishedProducts[i])) {
				NumOfFinishChipsProducts++;
			}
			else if (Milk* milk = dynamic_cast<Milk*>(FinishedProducts[i])) {
				NumOfFinishMilkProducts++;
			}
		}
		
		cout << " \n > We Have " << NumOfFinishMilkProducts << " Finished Milk Product .\n\n";
		cout << " > We Have " << NumOfFinishChipsProducts << " Finished Chips Product .\n";
	}
};