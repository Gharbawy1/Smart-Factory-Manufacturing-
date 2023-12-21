#ifndef DISTRIBUTIONOPERATION_H
#define DISTRIBUTIONOPERATION_H

#include "Operation.h"


class DistributionOperation : public Operation
{
    public:
        DistributionOperation()
        {
            this->estimated_time = chrono::milliseconds(1000); // 1000 mili second
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
        chrono::milliseconds GetSeconds() {
                    return estimated_time;
        }
        
    protected:

    private:
};

#endif // DISTRIBUTIONOPERATION_H
