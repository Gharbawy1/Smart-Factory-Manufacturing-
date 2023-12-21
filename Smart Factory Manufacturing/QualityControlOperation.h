#ifndef QUALITYCONTROLOPERATION_H
#define QUALITYCONTROLOPERATION_H

#include "Operation.h"


class QualityControlOperation : public Operation
{
    public:
        
        QualityControlOperation()
        {
            operationName="Quality Control ";
            this->estimated_time = chrono::milliseconds(1000); // 1000 mili second
        }
        virtual ~QualityControlOperation()
        {

        }
        void setName()
        {
            operationName="QualityControlOperation";
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

#endif // QUALITYCONTROLOPERATION_H
