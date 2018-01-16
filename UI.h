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

#ifndef UI_H
#define UI_H

#include <string>
using namespace std;

#include "ProdList.h"
#include "Store.h"
#include "OrderArray.h"

class UI{
    public:
        //void mainMenu(int&);
        // get choice from user input for adminMenu
        void adminMenu(int&);
        // get choice from user input for cashierMenu
        void cashierMenu(int&);
        // print string from input and prompt user for integer 
        void promptForInt(string, int&);
        // print string from input and prompt user for string
        void promptForStr(string, string&);
        // print string from input and prompt user for float
        void promptForFloat(string, float&);
        // print string from input and error message
        void printError(string);
        // print options for command line arguments
        void printUsageError();
        // print entire prodArray collection
        void printStock(ProdList*);
        // print entire customer collection and their purchase collection
        void printCustomers(list<Customer*>&);
        // print summary of total price and points earned from one transaction
        void printReceipt(int, float);
        // pause program and waits for user to continue
        void pause();
        // print entire orderArray collection and its purchArray
        void printOrders(OrderArray&);

        void adminProdTypes(int&);

    private:
        // read an int from user input
        int    readInt();
};

#endif
