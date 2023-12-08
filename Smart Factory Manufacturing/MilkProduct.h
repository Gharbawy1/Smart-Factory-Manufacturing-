#pragma once
#include"Proudct.h"
#include"Operation.h"
class Milk : public Product {
public:
    Milk() : brand("Unknown"), fat_percentage(3.5), expiration_date("2024-01-01"), state(IN_PROGRESS),NoOfOperations(0) {}
    Milk(const std::string& brand, double fat_percentage, const std::string& expiration_date) {
        this->brand = brand;
        this->fat_percentage = fat_percentage;
        this->expiration_date = expiration_date;
        NoOfOperations = 0;
    }
    string get_name() {
        return brand;
    }
    void SetData() {
        cout << "> Enter brand: ";
        cin >> this->brand;
        std::cout << "> Enter fat percentage (%): ";
        cin >> this->fat_percentage;
        std::cout << "> Enter expiration date (YYYY-MM-DD): ";
        cin >> this->expiration_date;
        cout << "\n\n > ";
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

    void AddOpertaion() {
        cout << "Choose The Sequance Of Operations : \n      [1] Processing  , [2] Inspection , [3] Quality Control , [4] Packging , [5] Distributuion.\n        ";
        int a, b, c; 
        cout << "\n      > Operation 1 : "; cin >> a;
        cout << "      > Operation 2 : "; cin >> b;
        cout << "      > Operation 3 : "; cin >> c;
        

        Operation* operationA = nullptr;
        Operation* operationB = nullptr;
        Operation* operationC = nullptr;
        switch (a)
        {
        case 1 :
            operationA = new ProcessingOperation;
            operationsContainer.push(operationA);
            NoOfOperations++;
            break;
        case 2 : 
            operationA = new InspectionOperation;
            operationsContainer.push(operationA);
            NoOfOperations++;
            break;
        case 3:
            operationA = new QualityControlOperation;
            operationsContainer.push(operationA);
            NoOfOperations++;
            break;
        case 4:
             operationA = new PackagingOperation;
                
                operationsContainer.push(operationA);
                NoOfOperations++;
                break;
        case 5:
                operationA = new DistributionOperation;
                  operationsContainer.push(operationA);
                    NoOfOperations++;
                    break;


        }
        switch (b)
        {
        case 1:
            operationB = new ProcessingOperation;
            operationsContainer.push(operationA);
            NoOfOperations++;
            break;
        case 2:
            operationB = new InspectionOperation;
            operationsContainer.push(operationA);
            NoOfOperations++;
            break;
        case 3:
            operationB = new QualityControlOperation;
            operationsContainer.push(operationA);
            NoOfOperations++;
            break;
        case 4:
            operationB = new PackagingOperation;

            operationsContainer.push(operationA);
            NoOfOperations++;
            break;
        case 5:
            operationB = new DistributionOperation;
            operationsContainer.push(operationA);
            NoOfOperations++;
            break;


        }
        switch (c)
        {
        case 1:
            operationC= new ProcessingOperation;
            operationsContainer.push(operationA);
            NoOfOperations++;
            break;
        case 2:
            operationC = new InspectionOperation;
            operationsContainer.push(operationA);
            NoOfOperations++;
            break;
        case 3:
            operationC = new QualityControlOperation;
            operationsContainer.push(operationA);
            NoOfOperations++;
            break;
        case 4:
            operationC = new PackagingOperation;

            operationsContainer.push(operationA);
            NoOfOperations++;
            break;
        case 5:
            operationC = new DistributionOperation;
            operationsContainer.push(operationA);
            NoOfOperations++;
            break;


        }
    }

    int GetNumberOfOperations() {
        return NoOfOperations;
    }

    /// <summary>
    /// Stop here 10:08
    /// => Confirm DeleteOperation 
    /// Link all project parts 
    /// main menu
    /// </summary>
    void DeleteOperation() {
        if (operationsContainer.IsEmpty()) {
            cout << "No Operation to delete :)\n";
            return;
        }
        cout << "Sure For removing The operation ? ";
        char c; cin >> c;
        if (c == 'y') {
            operationsContainer.pop();
            cout << "Operation Deleted Succseccfully . \n";
            NoOfOperations--;

        }

    }
    Stack operationsContainer;

private:
    std::string brand;
    double fat_percentage;
    STATE state;
    std::string expiration_date;
    int NoOfOperations;
};