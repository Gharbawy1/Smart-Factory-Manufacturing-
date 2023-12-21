#ifndef PACKAGINGOPERATION_H
#define PACKAGINGOPERATION_H

#include "Operation.h"


class PackagingOperation : public Operation
{
    public:

        PackagingOperation()
        {
            this->estimated_time = chrono::milliseconds(1000); // 1000 mili second

            operationName="Packaging ";

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
        chrono::milliseconds GetSeconds() {
            return estimated_time;
        }
    protected:

    private:
};

#endif // PACKAGINGOPERATION_H
