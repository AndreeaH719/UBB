#pragma once
#include "HospitalDepartment.h"

class Surgery:public HospitalDepartment
{
     private:
         int numberOfPatients;
     public:
         Surgery(string hospitalName, int numberOfDoctors, int numberOfPatients);
         bool isEfficient() override;
         string toString() override;
};

