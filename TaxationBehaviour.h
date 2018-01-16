#ifndef TAXATIONBEHAVIOUR_H
#define TAXATIONBEHAVIOUR_H

#include <string>

#include "defs.h"
using namespace std;

class TaxationBehaviour{
    public:
        // constructor
        TaxationBehaviour();
        // virtual destructor
        virtual ~TaxationBehaviour();
        // pure virtual function calculates tax, implemented in derived classes
        virtual float computeTax(float) = 0;

};

#endif
