#ifndef OPERATION_H
#define OPERATION_H
#include<iostream>
#include<thread>
#include<chrono>
using namespace std;
class Operation
{
private:
    //timer
public:
    string operationName;
    chrono::milliseconds estimated_time;

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
        output <<  op.operationName;
        return output;

    }
   /* void UpdateOperationState(int n) {
        if (n == 1) {
            Finish = true;
        }
    }*/
    virtual ~Operation() {

    }
    chrono::milliseconds GetSeconds() {
        return estimated_time;
    }

protected:

};
#endif // OPERATION_H