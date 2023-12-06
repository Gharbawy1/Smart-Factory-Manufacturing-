#pragma once
#include<iostream>
#include<string>
#include <iomanip>  
#include <sstream>  
using namespace std;
#include"Stack.h"

enum STATE
{
    IN_PROGRESS = 0,
    FINISHED = 1

};

class Product {
public:
    virtual std::string get_name()  = 0;
    //virtual void AddOpertaion() = 0; // not done
    //virtual void DeleteOperation() = 0;
    virtual void SetData() = 0;
    virtual void DisplayProductData() = 0;

protected:

};


