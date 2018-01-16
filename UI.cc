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

#include <iostream>
#include <iomanip>
#include <sstream>
#include "UI.h"
using namespace std;


void UI::adminMenu(int& choice){
    string str;

    choice = -1;

    cout<< "\n\n\n                   INVENTORY MANAGEMENT SYSTEM ADMIN MENU\n\n";
    cout<< "          1. Add new product \n\n";
    cout<< "          2. Add more inventory \n\n";
    cout<< "          3. Remove product \n\n";
    cout<< "          4. Print inventory \n\n";
    cout<< "          5. Print customers \n\n";
    cout<< "          6. Print Orders \n\n";
    cout<< "          0. Exit\n\n";

    while (choice < 0 || choice > 6) {
        cout << "Enter your selection:  ";
        choice = readInt();
    }
}

void UI::adminProdTypes(int& choice){
    string str;

    choice = -1;

    cout<< " PRODUCT TYPES \n\n";
    cout<< "          1. Dairy \n\n";
    cout<< "          2. CoffeeTea \n\n";
    cout<< "          3. Bakery \n\n";
    cout<< "          4. Meat \n\n";
    cout<< "          5. MiscGoods \n\n";
    cout<< "          0. Exit\n\n";

    while (choice < 0 || choice > 5) {
        cout << "Enter your selection:  ";
        choice = readInt();
    }
}

void UI::cashierMenu(int& choice){
    string str;

    choice = -1;

    cout<< "\n\n\n                   INVENTORY MANAGEMENT SYSTEM CASHIER MENU\n\n";
    cout<< "          1. Product purchases\n\n";
    cout<< "          2. Product returns\n\n";
    cout<< "          0. Exit\n\n";

    while (choice < 0 || choice > 2) {
        cout << "Enter your selection:  ";
        choice = readInt();
        if (choice == MAGIC_NUM) 
            return;
    }
}

void UI::printStock(ProdList* list){
    // The stringstream class helps us convert from numeric values to string.
    // The I/O manipulation functions help us make the output look pretty.

    //stringstream ss;

    cout << endl << "STOCK: " << endl << endl;
    cout << " ID                                 Name             Size    Qty    Price   Exp Date" << endl;
    cout << " --                                 ----             ----    ---    -----   --------" << endl;

    string products;
    list->toString(products);
    cout << products << endl;
}

void UI::printCustomers(list<Customer*>& arr){
  
    cout << endl << "CUSTOMERS:                    PURCHASES: " << endl << endl;
    cout <<         " ID      Name     Points      ID     Units" << endl;
    cout <<         " --      ----     ------      --     -----" << endl;
    string customers;
    list<Customer*>::iterator itr;
    for(itr = arr.begin(); itr != arr.end(); ++itr){
        cout << (*(itr))->getId() << setw(12)
        << (*(itr))->getName() << setw(8)
        << (*(itr))->getPoints();
        string purch;
        (*(itr))->getPurchases().toString(purch);
        cout << purch << endl;
    }
}

void UI::printReceipt(int points, float total){
    stringstream ss;

    cout << endl << "RECEIPT: " << endl;
    ss << fixed << setprecision(2) << total;
    cout << "TOTAL: $" << ss.str() << endl;
    cout << "POINTS EARNED: " << points << endl;
}

void UI::printOrders(OrderArray& arr){
    cout << endl;
    cout << "ORDERS:                       PURCHASES:" << endl << endl;
    cout << "ID     Cost     Customer      ID     Units" << endl;
    cout << "--     ----     --------      --     -----" << endl;
    string orders;
    arr.toString(orders);
    cout << orders;
}

void UI::printError(string err){
    cout << endl << err << " -- press enter to continue...";
    cin.get();
}

void UI::printUsageError(){
    cout << endl << "Usage:  cushop OPTION" << endl << endl;
    cout <<         "        where OPTION is either: " << endl;
    cout <<         "              -a  Admin menu"        << endl;
    cout <<         "              -c  Cashier menu"      << endl << endl;
}

void UI::promptForInt(string prompt, int& num){
    cout << prompt << ": ";
    num = readInt();
}

void UI::promptForStr(string prompt, string& str){
    cout << prompt << ": ";
    getline(cin, str);
}

void UI::promptForFloat(string prompt, float& num){
    string str;

    cout << prompt << ": ";
    getline(cin, str);

    stringstream ss(str);
    ss >> num;
}

int UI::readInt(){
    string str;
    int    num;

    getline(cin, str);
    stringstream ss(str);
    ss >> num;

    return num;
}

void UI::pause(){
    string str;

    cout << endl << "\nPress enter to continue...";
    getline(cin, str);
}

