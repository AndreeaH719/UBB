#pragma once
#include "Controller.h"

class service
{
     private:
         Controller &con;
     public:
         service(Controller &c);
         void addDepartment(HospitalDepartment* d);
         vector<HospitalDepartment*> getAllDepartments();
         vector<HospitalDepartment*> getAllEfficients();
         void writeToFile(string filename);
         void addentities();
};

