#ifndef EXPIRATIONBEHAVIOUR_H
#define EXPIRATIONBEHAVIOUR_H

#include <string>
#include "Date.h"
#include "defs.h"
using namespace std;

class ExpirationBehaviour{
    public:
        // constructor
        ExpirationBehaviour();
        // virtual destructor 
        virtual ~ExpirationBehaviour();
        // pure virtual function to calculate expiry date, implemented in derived classes
        virtual Date computeExpDate(Date&,int) = 0;

};

#endif
