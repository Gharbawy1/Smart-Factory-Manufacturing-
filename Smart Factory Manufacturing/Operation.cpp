#include "Operation.h"

Operation::Operation()
{
}

Operation::~Operation()
{
    //dtor
}
Operation::Operation(string name)
{
    operationName = name;
}
void Operation::setName(string name)
{
    operationName = name;
}
string Operation::getName()
{
    return operationName;
}
