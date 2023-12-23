#pragma once
#include"Proudct.h"
#include"Operation.h"
#include<conio.h>
#include<Windows.h>
using namespace chrono;

class Milk : public Product {
public:
    const int DEFAULT_COLOR = 7; // White
    const int HIGHLIGHT_COLOR = 10; // Green

    void setConsoleColor(int color) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    }

    void drawMenu(int option) {
        system("cls");
        cout << "Choose The Sequence Of Operations : \n";
        for (int i = 1; i <= 5; ++i) {
            if (i == option) {
                setConsoleColor(HIGHLIGHT_COLOR);
                cout << "\t ---> [" << i << "]  ";
            }
            else {
                setConsoleColor(DEFAULT_COLOR);
                cout << "\t[" << i << "] ";
            }

            switch (i) {
            case 1:
                cout << "Processing ";
                break;
            case 2:
                cout << "Inspection ";
                break;
            case 3:
                cout << "Quality Control ";
                break;
            case 4:
                cout << "Packaging ";
                break;
            case 5:
                cout << "Distribution ";
                break;
            }

            cout << "\n";
        }
        setConsoleColor(DEFAULT_COLOR); // Reset color to default after drawing menu
    }
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
        std::cout << "\t> Enter fat percentage (%): ";
        cin >> this->fat_percentage;
        std::cout << "\t> Enter expiration date (YYYY-MM-DD): ";
        cin >> this->expiration_date;
        cout << "\n\n > ";
    }
    void DisplayProductData() {
        std::ostringstream formattedData;
        // Set precision for displaying floating-point numbers
        formattedData << std::fixed << std::setprecision(2);
        formattedData << "> Brand: " << brand << "\n";
        formattedData << "> Fat Percentage: " << fat_percentage << "%\n";
        formattedData << "> Expiration Date: " << expiration_date << "\n\n";
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
        int option = 1;
        
        for (int i = 0; i < 3; i++) {
            Operation* operationA = nullptr;
            while (true)
            {
                drawMenu(option);
                cout << "\n      > Operation "<< i+1 <<" : "; 
                char key = _getch();
                if (key == '\r') { // enter
                    switch (option)
                    {
                    case 1:
                        operationA = new ProcessingOperation;
                        operationsContainer.push(operationA);
                        NoOfOperations++;
                        break;
                    case 2:
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
                    break;
                }
                else if (key == 72 && option > 1) { // Up arrow 
                    option--;
                }
                else if (key == 80 && option < 5) { //down arrow 
                    option++;
                }





            }
        }
    }
    int GetNumberOfOperations() {
        return NoOfOperations;
    }
    void DeleteOperation() {
        if (operationsContainer.IsEmpty()) {
            cout << "No Operation to delete :)\n";
            return;
        }
       /* cout << "Sure For removing The operation ? ";
        char c; cin >> c;
        if (c == 'y') {*/
        cout << " > This Milk product complete "<< *operationsContainer.pop()<<"process and";
        
            cout << " Operation Finished Succseccfully . \n";
            NoOfOperations--;

       // }

    }
  
    
    void process_product1() {
        using namespace std;
        using namespace chrono;
        milliseconds estimated_time(0);

        for (int i = 0; i < NoOfOperations; i++) {
            auto seconds_duration = operationsContainer[i]->GetSeconds();
            // Convert seconds to milliseconds using duration_cast
            estimated_time += duration_cast<milliseconds>(seconds_duration);
        }
        // Convert estimated_time to DWORD
        DWORD durationMs = static_cast<DWORD>(estimated_time.count());
        Sleep(durationMs);
    }
    void process_product() {
        using namespace std;
        using namespace chrono;

        for (size_t i = 0; i < NoOfOperations; ++i) {
            Operation* currentOperation = operationsContainer   [i];
            cout << "    " << currentOperation->operationName << " Operation in processing ";
            for (int seconds = currentOperation->estimated_time.count()/250; seconds > 0; --seconds) {
                cout << ".";
                this_thread::sleep_for(1s);
            }
            cout << " \t\t > " << currentOperation->operationName << " finished." << endl;
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