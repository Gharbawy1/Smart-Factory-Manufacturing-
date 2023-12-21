#ifndef INSPECTIONOPERATION_H
#define INSPECTIONOPERATION_H

#include "Operation.h"


class InspectionOperation : public Operation
{
    public:

        InspectionOperation()
        {
            this->estimated_time = chrono::milliseconds(1000); // 1000 mili second

            operationName="Inspection ";
        }
        virtual ~InspectionOperation()
        {

        }
        void setName()
        {
            operationName="InspectionOperation";
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

#endif // INSPECTIONOPERATION_H
