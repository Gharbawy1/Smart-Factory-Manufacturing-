#ifndef OPERATION_H
#define OPERATION_H
#include<iostream>
using namespace std;
class Operation
{
private:
    //timer
public:
    string operationName;
    //bool Finish;

    Operation() {
      //  Finish = false;
        operationName = "No name";
    }

    void setName(std::string name) {
        operationName = name;
    }
    std::string getName();
    friend ostream& operator <<(ostream& output, Operation& op)
    {
        output << "Name: " << op.operationName << endl;
        return output;

    }
   /* void UpdateOperationState(int n) {
        if (n == 1) {
            Finish = true;
        }
    }*/
    virtual ~Operation() {

    }

protected:

};
#endif // OPERATION_H