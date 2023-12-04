#include "MilkProduct.h"
void Milk::SetData() {

    cout << "Enter brand: ";
    cin >> this->brand;

    std::cout << "Enter fat percentage (%): ";
    cin >> this->fat_percentage;

    std::cout << "Enter expiration date (YYYY-MM-DD): ";
    cin >> this->expiration_date;

}