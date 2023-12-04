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

    void SetData();





};
