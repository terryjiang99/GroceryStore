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

#ifndef INVCONTROL_H
#define INVCONTROL_H

#include "Store.h"
#include "UI.h"
#include "OrderServer.h"

class InvControl{
    public:
        // constructor initializes hardcoded customers&products
        InvControl();
        // makes choice from command line args
        void launch(int, char*[]);
    private:
        Store     store;
        UI        view;
        OrderServer orderF;
        // initialize hardcoded products
        void      initProducts();
        // initialize hardcoded customers
        void      initCustomers();
        // process choices for admin menu
        void      processAdmin();
        // process choices for cashier menu
        void      processCashier();
};
#endif
