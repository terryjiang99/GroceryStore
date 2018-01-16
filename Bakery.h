#ifndef BAKERY_H
#define BAKERY_H

#include <string>
#include "Product.h"
using namespace std;

class Bakery : public Product{
    public:
        // constructor initializes data members, default: initialize to unknown and 0
        Bakery(string="?",string="?",int=0,float=0.0f,int=0,int=0,int=0,int=0);
        // virtual destructor
        virtual ~Bakery();
};

#endif
