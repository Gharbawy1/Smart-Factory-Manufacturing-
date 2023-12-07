#ifndef OPERATION_H
#define OPERATION_H
#include<iostream>
using namespace std;
class Operation
{
private:
    string operationName;
    //timer

public:
    Operation();

    Operation(std::string name);
    void setName(std::string name);
    std::string getName();
    friend ostream& operator <<(ostream& output, Operation& op)
    {
        output << "Name: " << op.operationName << endl;
        return output;

    }
     virtual ~Operation();

protected:

};

#endif // OPERATION_H
