#pragma once
#include"Proudct.h"

class Milk : public Product {
public:
    Milk() : brand("Unknown"), fat_percentage(3.5), expiration_date("2024-01-01"), state(IN_PROGRESS) {}

    Milk(const std::string& brand, double fat_percentage, const std::string& expiration_date) {
        this->brand = brand;
        this->fat_percentage = fat_percentage;
        this->expiration_date = expiration_date;
    }
    string get_name() {
        return brand;
    }
    void SetData() {
        cout << "Enter brand: ";
        cin >> this->brand;

        std::cout << "Enter fat percentage (%): ";
        cin >> this->fat_percentage;

        std::cout << "Enter expiration date (YYYY-MM-DD): ";
        cin >> this->expiration_date;
    }
    void DisplayProductData() {
        std::ostringstream formattedData;

        // Set precision for displaying floating-point numbers
        formattedData << std::fixed << std::setprecision(2);

        formattedData << "Brand: " << brand << "\n";
        formattedData << "Fat Percentage: " << fat_percentage << "%\n";
        formattedData << "Expiration Date: " << expiration_date << "\n";

        std::cout << formattedData.str();
    }
    void UpdateState(int val) {
        if (val == 1) {
            state = FINISHED;
        }
        else {
            // here throw an exeption
        }

    }
    STATE GetState() {
        return this->state;
    }
    
    //  ERROR UNRESOLVED EROEE I STOP HERE ----- 
    /*void AddOpertaion() {
        cout << "Choose which operaion : [1] operatoin 1 , [2] operation2";
        Operation* op; op = new Operation; op->setName("Pacjing");
        operationsContainer.push(op);
    }*/
    
private:
    std::string brand;
    double fat_percentage;
    STATE state;
    std::string expiration_date;
    
    Stack operationsContainer;
    int NoOfOperations;

};





