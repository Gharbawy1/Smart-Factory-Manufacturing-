#pragma once
#include"Stack.h"
#include"Operation.h"
#include"DistributionOperation.h"
#include"InspectionOperation.h"
#include"PackagingOperation.h"
#include"ProcessingOperation.h"
#include"QualityControlOperation.h"
#include<iostream>
#include<string>
#include <iomanip>  
#include <sstream> 

using namespace std;
enum STATE
{
    IN_PROGRESS = 0,
    FINISHED = 1
};
class Product {
public:
        virtual std::string get_name() = 0;

        virtual void AddOpertaion() = 0;// not done
    
        virtual void DeleteOperation() = 0;

        virtual void SetData() = 0;
        virtual void DisplayProductData() = 0;
        virtual void UpdateState(int) = 0;
        virtual STATE GetState() = 0;

       virtual void process_product() = 0;

        virtual int GetNumberOfOperations() = 0;


    protected:
};