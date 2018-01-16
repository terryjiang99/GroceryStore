#ifndef TAXABLE_H
#define TAXABLE_H

#include <string>
#include "TaxationBehaviour.h"
#include "defs.h"
using namespace std;

class Taxable : public TaxationBehaviour{
    public:
        // constructor 
        Taxable();
    protected: 
        // implementation for pure virtual function in TaxationBehaviour
        virtual float computeTax(float);

};

#endif
