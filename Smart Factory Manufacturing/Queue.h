#pragma once
#include"Proudct.h"
#include"MilkProduct.h"
#include"ChipsProduct.h"
#include<iostream>
#include<conio.h>
#include<iomanip>
#include<Windows.h>
#include<string>
using namespace std;
class QueueNode {
private:
	Product** data;
	int size;
	int NoElment;
	int front;
	int rear;
	// for manufactruing process
	static int FinishedMilk;
	static int FinishedChips;

public:
     //static int NumOfMilkProducts;
	 //static int NumOfChipsProducts;
	

	QueueNode* next;
	QueueNode* prev;
	QueueNode(int init);
	void InsertNewProduct();
	void RemoveAProduct(); // from front -> Shif Or circural
	int GetNumberOfElments();
	bool IsFull();
	bool IsEmpty();
	void DisplayProducts();

	void Manufactor();
	/*void CalcProducts();
	int GetNumOfMilkProducts();
	int GetNumOfChipsProducts();*/

	Product* GetFront();

};