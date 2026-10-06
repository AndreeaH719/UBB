#pragma once
#include "MedicalAnalysis.h"

class BP:public MedicalAnalysis
{
    private:
         int systolicValue;
         int diastolicValue;
    public:
         BP(string date, int systolicValue, int diastolicValue);
         bool isResultOk() override;
         string toString() override;
};

