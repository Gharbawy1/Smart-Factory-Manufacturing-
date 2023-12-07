#include "Operation.h"

Operation::Operation()
{
    operationName="No name";
}

Operation::~Operation()
{
    //dtor
}
Operation::Operation(string name)
{
    operationName=name;
}

string Operation::getName()
{
    return operationName;
}
