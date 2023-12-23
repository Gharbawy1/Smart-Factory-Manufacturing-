#pragma once
#include"Queue.h"
#include"Stack.h"
#include"Proudct.h"
#include<vector>
#include<Windows.h>
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
	
	const int DEFAULT_COLOR = 7; // White
	const int HIGHLIGHT_COLOR = 10; // Green
	void setConsoleColor(int color) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	}
	void drawMenu(int option) {
		system("cls");

		cout << "\n\n\t==> FINISH :\n";
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
				cout << "Operation By Operation . ";
				break;
			case 2:
				cout << "Finish All Operations. ";
				break;

			}
			cout << "\n";
		}
		setConsoleColor(DEFAULT_COLOR);
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
		int option = 1;
		while (true) {
			drawMenu(option);
			char key = _getch();
			if (key == '\r') { // Enter key pressed

				switch (option) {
				case 1:
					FinishOneOperatoin();
					break;
				case 2:
					DeleteProduct();
					break;
				}
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
			cout << "\n > Sure For Finish All these operations ? Press Enter Please";
			char key = _getch();
			cout << endl;
			if (key=='\r') {
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
	
	// unit to help me in manufacting process showing 
	void DeleteAllProducts() {
		while (Head != nullptr)
		{
			QueueNode* temp = Head;
			Head = Head->next;
			delete temp;
		}
	}


	bool HeadExist() {
		return Head != NULL;
	}
	void DisplayProducts() {
		if (FinishedCounter != 0) {
			cout << " >> We Have " << abs(NumOfAllProducts - FinishedCounter) << " Product In This Factory In Procissing \n\n";
		}
		else {
			cout << " >> We Have " << abs(NumOfAllProducts) << " Product In This Factory In Procissing \n\n";
		}
		QueueNode* t = this->Head;
		while (t)
		{
			t->DisplayProducts();
			if (t->next) {
				cout << "====================================\n";
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



	void Display_manu() {
		QueueNode* t = this->Head;
		while (t)
		{
			t->Manufactor();
			cout << "\t\t \n\n";
			//DisplayNumOfFinishedProducts();
			t = t->next;

		}
		DeleteAllProducts();
	}
};