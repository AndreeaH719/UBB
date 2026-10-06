#pragma once
#include "HospitalDepartment.h"
#include <vector>
class Controller
{
     private:
         vector<HospitalDepartment*> elems;
     public:
         Controller();
         void addDepartment(HospitalDepartment* d);
         vector<HospitalDepartment*> getAllDepartments();
         vector<HospitalDepartment*> getAllEfficients();
         void writeToFile(string filename);
};

