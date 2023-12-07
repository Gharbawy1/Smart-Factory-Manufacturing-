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
    Operation()
    {
        operationName = "no name";
    }

    Operation(std::string name)
    {
        operationName = name;

    }
    void setName(std::string name)
    {
        operationName = name;

    }
    std::string getName()
    {
        return operationName;
    }
    friend ostream& operator <<(ostream& output, Operation& op)
    {
        output << "Name: " << op.operationName << endl;
        return output;

    }
    virtual ~Operation()
    {

     }

protected:

};

#endif // OPERATION_H
