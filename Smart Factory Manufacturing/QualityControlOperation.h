#ifndef QUALITYCONTROLOPERATION_H
#define QUALITYCONTROLOPERATION_H

#include "Operation.h"


class QualityControlOperation : public Operation
{
    public:
        QualityControlOperation()
        {
            operationName="Quality Control Operation";
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
    protected:

    private:
};

#endif // QUALITYCONTROLOPERATION_H
