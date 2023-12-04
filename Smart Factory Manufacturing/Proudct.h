#include<iostream>
usnig namespace std;

class Product {
public:
    virtual ~Product() {}
    virtual std::string get_name()  = 0;
    virtual double get_price()  = 0;
};