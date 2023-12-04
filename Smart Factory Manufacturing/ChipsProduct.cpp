#include"ChipsProduct.h"
void Chips::SetData() {
    cout << "Enter brand: ";
    cin >> this->brand;

    std::cout << "Enter flavor: ";
    cin >> this->flavor;

    std::cout << "Enter weight (g): ";
    cin >> this->weight;

    std::cout << "Enter price: ";
    cin >> this->price;

}