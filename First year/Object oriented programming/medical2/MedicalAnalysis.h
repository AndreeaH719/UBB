#pragma once
#include <string>
using namespace std;

class MedicalAnalysis
{
     protected:
         string date;
     public:
         MedicalAnalysis(string date);
         virtual bool isResultOk() = 0;
         virtual string toString() = 0;
         virtual ~MedicalAnalysis() = default;
         string getDate() {return date;}
};

