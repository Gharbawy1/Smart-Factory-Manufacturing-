#ifndef OPERATION_H
#define OPERATION_H

#include<iostream>
using namespace std;
class Operation
{
        protected:
            string operationName;
            //timer

    public:
        Operation();
        Operation(string name);
        virtual void setName()=0;
         virtual string getName()=0;
        friend ostream&operator <<(ostream&output,Operation&op)
    {
        output<<"Name: "<< op.operationName<<endl;
        return output;

    }
        virtual ~Operation();

    protected:

};

#endif // OPERATION_H
