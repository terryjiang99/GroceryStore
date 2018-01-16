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

#include <cstdlib>
#include <iostream>
#include <cmath>
#include "InvControl.h"
using namespace std; 

InvControl::InvControl(){
    initProducts();
    initCustomers();
}

void InvControl::launch(int argc, char* argv[]){
    if (argc != 2) {
        view.printUsageError();
        exit(1);
    }

    string option(argv[1]);

    if (option == "-a") {		// Admin menu
        processAdmin();
    }
    else if (option == "-c") {	// Cashier menu
        processCashier();
    }
    else {
        view.printUsageError();
        exit(1);
    }
}

void InvControl::processAdmin(){
    int    choice;
    string prodName, prodSize;
    int    prodUnits, prodId, amount, pType, day, month, year, ls;
    float  prodPrice;

    while (1) {
        choice = -1;
        view.adminMenu(choice);
        if (choice == 1) {		// add new product
            Product* prod;
            view.adminProdTypes(pType);
            view.promptForStr("Product name", prodName);
            view.promptForStr("Product size", prodSize);
            view.promptForInt("# units", prodUnits);
            view.promptForFloat("Price", prodPrice);
            view.promptForInt("Manufacturing Day", day);
            view.promptForInt("Manufacturing Month", month);
            view.promptForInt("Manufacturing Year", year);
            view.promptForInt("Lifespan", ls);
            if(pType == 1){
                prod = new Dairy(prodName, prodSize, prodUnits, prodPrice, day, month, year, ls);
            }
            else if(pType == 2){
                prod = new CoffeeTea(prodName, prodSize, prodUnits, prodPrice, day, month, year,ls);
            }
            else if(pType == 3){
                prod = new Bakery(prodName, prodSize, prodUnits, prodPrice, day, month, year, ls);
            }
            else if(pType == 4){
                prod = new Meat(prodName, prodSize, prodUnits, prodPrice, day, month, year, ls);
            }
            else if(pType == 5){
                prod = new MiscGoods(prodName, prodSize, prodUnits, prodPrice, day, month, year,ls);
            }
            else{
                break;
            }
            store.addProd(prod);
            view.pause();
        }
        else if (choice == 2) {	// add inventory
            view.promptForInt("Enter the product ID", prodId);
            Product* prod = store.findProd(prodId);
            while(prod == NULL){
                view.promptForInt("Product not found, enter another ID", prodId);
                prod = store.findProd(prodId);
            }
            view.promptForInt("Enter the number of new units", prodUnits);
            prod->increaseUnits(prodUnits);
            store.reorg();
            view.printError("Inventory updated");
        }
        else if (choice == 3){
            view.promptForInt("Enter the product ID", prodId);
            Product* prod = store.findProd(prodId);
            while(prod == NULL){
                view.promptForInt("Product not found, enter another ID", prodId);
                prod = store.findProd(prodId);
            }
            store.removeProd(prod);
            view.printError("Product removed");
        }
        else if (choice == 4) {	// print inventory
            view.printStock(store.getStock());
            view.pause();
        }
        else if (choice == 5) {	// print customers
            view.printCustomers(store.getCustomers());
            view.pause();
        }
        else if (choice == 6) { // print orders
            OrderArray orders;
            orderF.retrieve(orders);
            view.printOrders(orders);
            view.pause();
        }
        else {
          break;
        }
    }
}

void InvControl::processCashier()
{
    int choice, prodId, custId;

    while (1) {
        choice = -1;
        view.cashierMenu(choice);
        if (choice == 1) {			// purchases
            int lpoints = 0;
            float totalPrice = 0;
            bool bought = false;

            view.promptForInt("Enter your Customer ID", custId);
            Customer* cust = store.findCust(custId);
            while(cust == NULL){
                view.promptForInt("Customer not found. Enter another customer ID", custId);
                cust = store.findCust(custId);
            }
            Order* order = new Order(cust);
            while(1){
                bool exit = false;

                view.promptForInt("Enter a product ID to purchase or 0 when finished", prodId);

                Product* prod = store.findProd(prodId);
                while(prodId == 0 || prod == NULL || prod->getUnits() < 1){
                    if(prodId == 0){
                        exit = true;
                        break;
                    }
                    view.promptForInt("Product not found or has no units left, enter a different ID or 0 to exit", prodId);
                    prod = store.findProd(prodId);
                }
                if(exit){
                    if(!bought){
                        delete order;
                    }else{
                        order->setCost(totalPrice);
                        orderF.update(order);
                        lpoints = round(totalPrice);
                        cust->addPoints(lpoints);
                        view.printReceipt(lpoints, totalPrice);
                    }
                    break;
                }
                totalPrice += prod->getPrice();
                totalPrice += prod->computeTax();
                cust->addPurch(prodId);
                prod->decreaseUnits();
                order->addPurch(prodId);
                store.reorg();
                bought = true;
            }
        }

        else if (choice == 2) {		// return purchases
            view.printError("Feature not implemented");
        }
        else if (choice == MAGIC_NUM) {	// print inventory and customers
            OrderArray orders;
            orderF.retrieve(orders);
            view.printStock(store.getStock());
            view.printCustomers(store.getCustomers());
            view.printOrders(orders);
            view.pause();
        }
        else {
            break;
        }
    }
}

void InvControl::initProducts(){
  /*
     This function is so ugly!  It's because we're using 
     statically allocated memory, instead of dynamically
     alloated.  Don't worry, we'll fix this in Assignment #2.
  */
    Product* prod;

    prod = new MiscGoods("Sudzzy Dish Soap", "1 L", 10, 3.99f, 2,4,2012,2);
    store.addProd(prod);

    prod = new MiscGoods("Peachy Laundry Soap", "2 L", 3, 8.99f, 2,6,2010,3);
    store.addProd(prod);

    prod = new MiscGoods("Daisy's Spicy Chili", "150 g", 5, 1.29f, 20,5,1992,99);
    store.addProd(prod);

    prod = new MiscGoods("Daisy's Maple Baked Beans", "220 g", 2, 2.49f, 24,5,2002,1);
    store.addProd(prod);

    prod = new Bakery("Belmonts", "20-pack", 69, 4.99f, 4,2,1997,200);
    store.addProd(prod);

    prod = new Meat("Garfield Hamburger Patties", "900 g", 2, 11.99f,12,11,2011,20);
    store.addProd(prod);

    prod = new Dairy("Chunky Munkey Ice Cream", "2 L", 1, 2.97f,20,1,2009,8);
    store.addProd(prod);

    prod = new Dairy("It's Your Bday Chocolate Cake", "500 g", 0, 12.99f,22,3,2008,10);
    store.addProd(prod);

    prod = new MiscGoods("Happy Baker's Hot dog buns", "12-pack", 5, 3.49f,20,4,2010,2);
    store.addProd(prod);

    prod = new MiscGoods("Happy Baker's Hamburger buns", "8-pack", 8, 3.99f,29,3,2016,3);
    store.addProd(prod);

    prod = new Dairy("Moo-cow 2% milk", "1 L", 7, 2.99f,18,12,2010,49);
    store.addProd(prod);

    prod = new Dairy("Moo-cow 2% milk", "4 L", 3, 4.99f,20,6,2020,1);
    store.addProd(prod);

    prod = new Dairy("Moo-cow 5% coffee cream", "250 ml", 4, 1.49f,21,12,2006,10);
    store.addProd(prod);

    prod = new MiscGoods("Good Morning Granola Cereal", "400 g", 2, 5.49f,10,10,1000,23);
    store.addProd(prod);

    prod = new CoffeeTea("Lightening Bolt Instant Coffee", "150 g", 8, 4.99f,21,12,2010,3);
    store.addProd(prod);

    prod = new CoffeeTea("Lightening Bolt Decaf Coffee", "100 g", 2, 4.99f,14,7,1995,3);
    store.addProd(prod);

    prod = new MiscGoods("Munchies BBQ Chips", "250 g", 7, 2.99f,2,4,2002,2);
    store.addProd(prod);

    prod = new MiscGoods("Munchies Ketchup Chips", "250 g", 3, 2.99f,5,2,1999,3);
    store.addProd(prod);

    prod = new MiscGoods("Dogbert Salted Chips", "210 g", 4, 1.99f,6,7,2000,4);
    store.addProd(prod);

    prod = new MiscGoods("Dogbert Sweet and Spicy Popcorn", "180 g", 5, 2.29f,20,5,2004,2);
    store.addProd(prod);

}

void InvControl::initCustomers(){
    Customer* cust;
    cust = new Customer("T");
    store.addCust(cust);
    cust = new Customer("Th");
    store.addCust(cust);
    cust = new Customer("Thu");
    store.addCust(cust);
    cust = new Customer("Thuv");
    store.addCust(cust);
    cust = new Customer("Thuva");
    store.addCust(cust);
    cust = new Customer("Thuvar");
    store.addCust(cust);
    cust = new Customer("Thuvara");
    store.addCust(cust);
    cust = new Customer("Thuvarak");
    store.addCust(cust);
    cust = new Customer("Thuvaraka");
    store.addCust(cust);
    cust = new Customer("Thuvarakan");
    store.addCust(cust);
}

