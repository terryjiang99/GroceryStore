#ifndef NONTAXABLE_H
#define NONTAXABLE_H

#include <string>
#include "TaxationBehaviour.h"
using namespace std;

class NonTaxable : public TaxationBehaviour{
    public:
        // constructor
        NonTaxable();
    protected:
        // implementation for pure virtual function in TaxationBehaviour
        virtual float computeTax(float);
};

#endif
