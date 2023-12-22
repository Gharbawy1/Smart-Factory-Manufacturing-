#ifndef PROCESSINGOPERATION_H
#define PROCESSINGOPERATION_H

#include "Operation.h"


class ProcessingOperation : public Operation
{
    public:

        ProcessingOperation()
        {
            operationName="Processing ";
            this->estimated_time = chrono::milliseconds(1000); // 1000 mili second

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
        chrono::milliseconds GetSeconds() {
            return estimated_time;
        }
    protected:

    private:
};

#endif // PROCESSINGOPERATION_H
