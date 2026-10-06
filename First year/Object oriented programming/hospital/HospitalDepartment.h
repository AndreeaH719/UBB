#pragma once
#include <string>
using namespace std;

class HospitalDepartment
{
    protected:
        string hospitalName;
        int numberOfDoctors;
    public:
        HospitalDepartment(string hospitalName, int numberOfDoctors);
        virtual bool isEfficient() = 0;
        virtual string toString() = 0;
        virtual ~HospitalDepartment() = default;
        string getName() {return hospitalName;}
};

