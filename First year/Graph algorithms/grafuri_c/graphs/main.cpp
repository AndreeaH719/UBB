#include "GraphUi.h"

int main() {
    GraphRepo repo;
    Menu menu(&repo); 
    menu.run();       
    return 0;
}