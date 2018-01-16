#ifndef DAIRY_H
#define DAIRY_H

#include <string>
#include "Product.h"
using namespace std;

class Dairy : public Product{
    public:
        // constructor initializes data members, default: initialize to unknown and 0
        Dairy(string="?",string="?",int=0,float=0.0f,int=0,int=0,int=0,int=0);
        // virtual destructor
        virtual ~Dairy();
};

#endif
