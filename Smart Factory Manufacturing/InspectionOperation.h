#ifndef INSPECTIONOPERATION_H
#define INSPECTIONOPERATION_H

#include <Operation.h>


class InspectionOperation : public Operation
{
    public:
        InspectionOperation()
        {
            operationName="Inspection Operation";
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
    protected:

    private:
};

#endif // INSPECTIONOPERATION_H
