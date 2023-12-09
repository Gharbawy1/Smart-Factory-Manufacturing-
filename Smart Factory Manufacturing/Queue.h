#pragma once
#include"Proudct.h"
#include"MilkProduct.h"
#include"ChipsProduct.h"
#include<iostream>
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
	

public:
	static int NumOfFinishedMilkProducts;
	static int NumOfFinishedChipsProducts;
	QueueNode* next;
	QueueNode* prev;
	QueueNode(int init);
	void InsertNewProduct();
	void RemoveAProduct(); // from front -> Shif Or circural
	int GetNumberOfElments();
	bool IsFull();
	bool IsEmpty();
	void DisplayProducts();
	void CalcProducts();
	int GetNumOfMilkProducts();
	int GetNumOfChipsProducts();
	Product* GetFront();

};