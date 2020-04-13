#include <iostream>
#include "Registry.h"

int main() {

    Registry<const char *> *registry = new Registry<const char *>;

    registry->insertFront("nataliaserarols@ub.edu");
    registry->insert("bertasola@ub.edu");
    registry->insert("annabastida");
    registry->insert("kilianfarre@ub.edu");
    registry->insert("dianatorro@ub.edu");
    registry->print();

    cout << "" << endl;

    Registry<const char *> *registry_other = new Registry<const char *>;

    registry_other->insertFront("mireiafontarnau@ub.edu");
    registry_other->insert("rogercasaramona@ub.edu");
    registry_other->print();

    //registry->merge(&registry_other);


    return 0;
}
