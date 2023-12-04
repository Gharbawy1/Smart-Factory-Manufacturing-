#include"Proudct.h"

class Milk : public Product {
public:
    Milk(const std::string& brand, double fat_percentage, double price, const std::string& expiration_date);
    string get_name() const override;
    double get_price() const override;

private:
    string brand;
    double fat_percentage;
    double price;
    string expiration_date;
};