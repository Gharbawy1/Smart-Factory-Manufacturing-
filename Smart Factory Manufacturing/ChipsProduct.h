#pragma once
#include"Proudct.h"

class Chips : public Product {
private:
    string brand;
    string flavor;
    double weight;
    double price;

public:
    Chips() : brand("Generic"), flavor("Salted"), weight(250), price(1.99) {}
    Chips(const std::string& brnd, const std::string& flvr, double weigt, double pric) {
        brand = brnd;
        flavor = flvr;
        weight = weigt;
        price = pric;
    }
    string get_name() {
        return brand;
    }
    double get_price() {
        return price;
    }

    void SetData() {
        cout << "Enter brand: ";
        cin >> this->brand;

        std::cout << "Enter flavor: ";
        cin >> this->flavor;

        std::cout << "Enter weight (g): ";
        cin >> this->weight;

        std::cout << "Enter price: ";
        cin >> this->price;
    }
    void DisplayProductData() {
        std::ostringstream formattedData;

        formattedData << std::fixed << std::setprecision(2);

        formattedData << "Brand: " << brand << "\n";
        formattedData << "Flavor: " << flavor << "\n";
        formattedData << "Weight: " << weight << " grams\n";
        formattedData << "Price: $" << price << "\n";

        std::cout << formattedData.str();
    }




};
