#pragma once
#include"Proudct.h"
#include"MilkProduct.h"
#include"ChipsProduct.h"
#include<iostream>
#include<string>
using namespace std;


class QueueNode{
private:
	Product** data;
	int size;
	int NoElment;
	int front;
	int rear;

public:
	QueueNode* next;
	QueueNode* prev;
	QueueNode(int init);
	void InsertNewProduct();
	int RemoveAProduct(); // from front -> Shif Or circural
	int GetNumberOfElments();
	bool IsFull();
	bool IsEmpty();
	void DisplayProducts();
};



