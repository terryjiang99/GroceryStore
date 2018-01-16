#ifndef PERISHABLE_H
#define PERISHABLE_H

#include <string>
#include "ExpirationBehaviour.h"
using namespace std;

class Perishable : public ExpirationBehaviour{
    public:
        // constructor
        Perishable();
    protected:
        // implementation for pure virtual function in ExpirationBehaviour
        virtual Date computeExpDate(Date&, int);
};

#endif
