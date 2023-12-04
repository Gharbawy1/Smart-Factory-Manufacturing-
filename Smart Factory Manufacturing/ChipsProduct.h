#include"Proudct.h"

class Chips : public Product {
public:
    Chips(const std::string& brand, const std::string& flavor, double weight, double price);
    string get_name() const override;
    double get_price() const override;
   

private:
    string brand;
    string flavor;
    double weight;
    double price;
};
