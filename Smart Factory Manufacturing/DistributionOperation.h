#ifndef DISTRIBUTIONOPERATION_H
#define DISTRIBUTIONOPERATION_H

#include "Operation.h"


class DistributionOperation : public Operation
{
    public:
        DistributionOperation()
        {
            operationName="Distribution ";
        }
        virtual ~DistributionOperation()
        {

        }
        void setName()
        {
            operationName="Distribution Operation";
        }
                string getName()
        {
            return operationName;
        }
    protected:

    private:
};

#endif // DISTRIBUTIONOPERATION_H
