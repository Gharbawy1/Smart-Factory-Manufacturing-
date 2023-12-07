#ifndef PACKAGINGOPERATION_H
#define PACKAGINGOPERATION_H

#include "Operation.h"


class PackagingOperation : public Operation
{
    public:
        PackagingOperation()
        {
            operationName="Packaging Operation";

        }
        virtual ~PackagingOperation()
        {

        }
        void setName()
        {
            operationName="Packaging Operation";
        }
        string getName()
        {
            return operationName;
        }
    protected:

    private:
};

#endif // PACKAGINGOPERATION_H
