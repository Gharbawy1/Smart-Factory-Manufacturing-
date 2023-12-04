#pragma once
#include<iostream>
#include<string>
#include"Proudct.h"
#include"MilkProduct.h"
#include"ChipsProduct.h"
using namespace std;


class QueueNode{
private:
	Product** data;
	int size;
	int NoElment;
	QueueNode* next;
	int front;
	int rear;
public:
	QueueNode(int init);
	void InsertNewProduct();
	void RemoveAProduct(); // from front -> Shif Or circural
	int GetNumberOfElments();

};



