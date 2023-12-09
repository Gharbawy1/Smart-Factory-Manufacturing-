#pragma once
#include"Proudct.h"
#include"Operation.h"
class Chips : public Product {
private:
    string brand;
    string flavor;
    double weight;
    STATE state;
    int NoOfOperations;

    
public:
    Stack operationsContainer;
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

    Chips() : brand("Generic"), flavor("Salted"), weight(250), state(IN_PROGRESS) {}
    Chips(const std::string& brnd, const std::string& flvr, double weigt) {
        brand = brnd;
        flavor = flvr;
        weight = weigt;

    }
    string get_name() {
        return brand;
    }

    void SetData() {
        cout << "> Enter brand: ";
        cin >> this->brand;
        std::cout << "\t> Enter flavor: ";
        cin >> this->flavor;
        std::cout << "\t> Enter weight (g): ";
        cin >> this->weight;
    }
    void DisplayProductData() {
        std::ostringstream formattedData;
        formattedData << std::fixed << std::setprecision(2);
        formattedData << "> Brand: " << brand << "\n";
        formattedData << "> Flavor: " << flavor << "\n";
        formattedData << "> Weight: " << weight << " grams\n\n";
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
                cout << "\n      > Operation " << i + 1 << " : ";
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


    void DeleteOperation() {
        if (operationsContainer.IsEmpty()) {
            cout << "No Operation to delete :)\n";
            return;
        }
       // cout << "Sure For removing The operation ? ";
        /*char c; cin >> c;
        if (c == 'y') {*/
        cout << " > This Chips product complete " << *operationsContainer.pop() << "process and";

        cout << " Operation Finished Succseccfully . \n";
            NoOfOperations--;
        //}

    }

    int GetNumberOfOperations() {
        return NoOfOperations;
    }




};