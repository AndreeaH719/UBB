#pragma once
#include "HospitalDepartment.h"

class Unit:public HospitalDepartment
{
    private:
      int numberOfMothers;
      int numberOfNewborn;
      double averageGrade;
    public:
       Unit(string hospitalName, int numberOfDoctors, int numberOfMothers, int numberOfNewborn, double averageGrade);
       bool isEfficient() override;
       string toString() override;
};

