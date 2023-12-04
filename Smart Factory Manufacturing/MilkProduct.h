#pragma once
#include"Proudct.h"

class Milk : public Product {
public:
    Milk() : brand("Unknown"), fat_percentage(3.5), price(2.99), expiration_date("2024-01-01") {}

    Milk(const std::string& brand, double fat_percentage, double price, const std::string& expiration_date) {
        this->brand = brand;
        this->fat_percentage = fat_percentage;
        this->price = price;
        this->expiration_date = expiration_date;
    }
    string get_name() {
        return brand;
    }
    double get_price() {
        return price;
    }
    void SetData();

        
    
private:
    std::string brand;
    double fat_percentage;
    double price;
    std::string expiration_date;
};





