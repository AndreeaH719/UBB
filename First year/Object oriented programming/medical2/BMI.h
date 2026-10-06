#pragma once
#include "MedicalAnalysis.h"

class BMI:public MedicalAnalysis
{
    private:
        double value;
    public:
        BMI(string date, double value);
        bool isResultOk() override;
        string toString() override;
};

