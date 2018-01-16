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

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
using namespace std;

#include "PurchArray.h"
#include "Purchase.h"

class Customer{
    public:
        // constructor initializes data members, default: unknown name
        Customer(string="Unknown");
        // return customer id
        int    getId();
        // return customer name
        string getName();
        // return customer points
        int    getPoints();
        // return the purchase array
        PurchArray& getPurchases();
        // calls add function in purchArray class (prod purch feature)
        void addPurch(int);
        // add points to customer (prod purch feature)
        void addPoints(int&);
        // convert each data member to string in outparam
        void toString(string&);

    protected:
        static int nextCustId;
        int        id;
        string     name;
        int        points;
        PurchArray purchases;
};

#endif
