#ifndef PROCESSINGOPERATION_H
#define PROCESSINGOPERATION_H

#include "Operation.h"


class ProcessingOperation : public Operation
{
    public:
        ProcessingOperation()
        {
            operationName="Processing ";
        }
        virtual ~ProcessingOperation()
        {

        }
        void setName()
        {
            operationName="Processing Operation";
        }
        string getName()
        {
            return operationName;
        }
    protected:

    private:
};

#endif // PROCESSINGOPERATION_H
