#pragma once
#include "service.h"

class Ui
{
   private:
      Service &ser;
   public:
       Ui(Service &s);
       void run();

};

