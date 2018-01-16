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

#ifndef PRODLIST_H
#define PRODLIST_H

#include "defs.h"
#include "Product.h"

class ProdList{
    class Node{
        friend class ProdList;
        private:
            Product* data;
            Node* next;
            Node* prev;
    };
    public:
        // constructor initializes head to 0
        ProdList();
        ~ProdList();
        // add a product to ProdList in ascending order
        void add(Product*);
        // return product if in list, return null if not found
        Product* findProduct(int);
        // reorg implements bubble sort to sort in ascending,
        // called when product units change
        void reorg();
        // remove a product from List by ID
        void remove(Product*);
        // converts product data to string and return in outparameter
        void toString(string&);
        // cleanup deletes the nodes and the data, called from store destructor
        //void cleanUp();

    private:
        Node* head;
        //int size;
};

#endif

