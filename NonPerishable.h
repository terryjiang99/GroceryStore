#ifndef NONPERISHABLE_H
#define NONPERISHABLE_H

#include <string>
#include "ExpirationBehaviour.h"
#include "defs.h"
using namespace std;

class NonPerishable : public ExpirationBehaviour{
    public:
        // constructor 
        NonPerishable();
    protected: 
        // implementation for pure virtual function in ExpirationBehaviour
        virtual Date computeExpDate(Date&, int);
};

#endif
