#pragma once
#include<iostream>
#include<string>
#include <iomanip>  
#include <sstream>  
using namespace std;

class Product {
public:
    virtual std::string get_name()  = 0;
    virtual double get_price()  = 0;
    virtual void SetData() = 0;
    virtual void DisplayProductData() = 0;


};


