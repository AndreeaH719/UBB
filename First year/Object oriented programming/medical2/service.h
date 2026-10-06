#pragma once
#include "Person.h"

class service
{
     private:
         Person &per;
     public:
         service(Person &p);
         void addAnalysis(MedicalAnalysis* a);
         vector<MedicalAnalysis*> getAllAnalysis();
         vector<MedicalAnalysis*> getAnalyses1(int month);
         bool isIll(int month);
         vector<MedicalAnalysis*> getAnalyses2(string date1, string date2);
         void writeFile(string filename, string date1, string date2);
         void entities();
};

