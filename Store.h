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

#ifndef STORE_H
#define STORE_H
#include <list>

#include "ProdList.h"
#include "Product.h"
#include "Customer.h"
#include "Bakery.h"
#include "CoffeeTea.h"
#include "Dairy.h"
#include "Meat.h"
#include "MiscGoods.h"
using namespace std;

class Store{
    public:
        // destructor loops through list and deallocates customers
        ~Store();
        // calls prodArray's add function
        void       addProd(Product*);
        // calls custArrays's add function
        void       addCust(Customer*);
        // return product array
        ProdList* getStock();
        // return customer array
        list<Customer*>& getCustomers();
        // calls custArray's find function
        Customer* findCust(int);
        // calls prodLists's find function
        Product* findProd(int);
        // calls prodList's remove function
        void removeProd(Product*);
        // calls prodList's reorg function
        void reorg();

    private:
        ProdList  stock;
        list<Customer*>  customers;
};

#endif
