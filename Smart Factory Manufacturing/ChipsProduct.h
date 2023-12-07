#pragma once
#include"Proudct.h"
#include"Operation.h"
class Chips : public Product {
private:
    string brand;
    string flavor;
    double weight;
    STATE state;


    Stack operationsContainer;
    int NoOfOperations;
public:
    Chips() : brand("Generic"), flavor("Salted"), weight(250),state(IN_PROGRESS) {}
    Chips(const std::string& brnd, const std::string& flvr, double weigt) {
        brand = brnd;
        flavor = flvr;
        weight = weigt;
    
    }
    string get_name() {
        return brand;
    }
    
    void SetData() {
        cout << "Enter brand: ";
        cin >> this->brand;

        std::cout << "Enter flavor: ";
        cin >> this->flavor;

        std::cout << "Enter weight (g): ";
        cin >> this->weight;
    }
    void DisplayProductData() {
        std::ostringstream formattedData;

        formattedData << std::fixed << std::setprecision(2);

        formattedData << "Brand: " << brand << "\n";
        formattedData << "Flavor: " << flavor << "\n";
        formattedData << "Weight: " << weight << " grams\n";

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


    // AND HERE UNRESOLVE ERROR (EXTERNAL ERROR) :::(((
   /* void AddOpertaion() {
        cout << "Choose which operaion : [1] operatoin 1 , [2] operation2";
        Operation* op; op = new Operation; op->setName("Pacjing");
        operationsContainer.push(op);
    }

};
