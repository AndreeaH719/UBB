#include "repo.h"
#include "service.h"
#include "ui.h"
#include "test.h"

int main()
{

   test t;
   t.test_all();
   std::cout << "All test passed\n";
   Repo r;
   Service s(r);
   Ui u(s);
   s.pacients();
   u.run();
   return 0;

}