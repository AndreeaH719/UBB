#pragma once
#include "MedicalAnalysis.h"
#include <vector>
class Person
{
      private:
          vector<MedicalAnalysis*> analysis;
      public:
          Person();
          void addAnalysis(MedicalAnalysis* a);
          vector<MedicalAnalysis*> getAllAnalysis();
          vector<MedicalAnalysis*> getAnalyses1(int month);
          bool isIll(int month);
          vector<MedicalAnalysis*> getAnalyses2(string date1, string date2);
          void writeFile(string filename, string date1, string date2);
};

