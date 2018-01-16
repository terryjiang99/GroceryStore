/* * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                 */
/*  Program:  Simple Inventory System              */
/*  Author:   Christine Laurendeau                 */
/*  Date:     28-JUN-2016                          */
/*                                                 */
/*  (c) 2016 Christine Laurendeau                  */
/*  All rights reserved.  Distribution and         */
/*  reposting, in part or in whole, without the    */
/*  written consent of the author, is illegal.     */
/*                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include "Date.h"
#include "TaxationBehaviour.h"
#include "ExpirationBehaviour.h"
#include "Perishable.h"
#include "Taxable.h"
#include "NonPerishable.h"
#include "NonTaxable.h"
using namespace std;

class Product{
    public:
        // constructor initializes data members, default: initialize to unknown and 0
        Product(string="?", string="?", int=0, float=0.0f, int=0, int=0, int=0, int=0);
        virtual ~Product();
        // return product id
        int    getId();
        // return product name
        string getName();
        // return product size
        string getSize();
        // return product num of units
        int    getUnits();
        // return product price
        float  getPrice();
        // decrease units after a sale (make purch feature)
        void decreaseUnits();
        // increase units by amount from input, (add more inv feature)
        void increaseUnits(int);
        // convert each data member to string to outparam
        void toString(string&);
        // call computetax from TaxationBehaviour
        float computeTax();
        // return expiry date
        Date& geteDate();

    protected:
        static int nextProdId;
        int        id;
        string     name;
        string     size;
        int        units;
        float      price;
        Date mDate;
        Date eDate;
        TaxationBehaviour* taxb;
        ExpirationBehaviour* expb;
        int lifespan;
        // call computeExpDate from ExpirationBehaviour
        Date computeExpDate();

};

#endif
