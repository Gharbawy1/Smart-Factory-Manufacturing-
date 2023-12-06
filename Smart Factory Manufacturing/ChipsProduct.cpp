#include"ChipsProduct.h"
//void Chips::SetData() {
//    
//}

//void Chips::DisplayProductData() {
//   
//
//}

void Chips::AddOpertaion(){
        cout << "Choose which operaion : [1] operatoin 1 , [2] operation2";
        Operation* op; op = new Operation; op->setName("Pacjing");
        operationsContainer.push(op);
    }