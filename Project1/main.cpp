/*
Stanley Su
CSCI 235 - Tiziana Ligorio
Project 1 is about making a scheduling program that will display the Customers
information such as name, device, wait time. This program will also display
the Geniusbar status such as how many workers, if they are helping anyone, 
if they are free etc.  
*/

#include<iostream>
#include<string>
#include "GeniusBar.h"
#include "Customer.h"
using namespace std;

int main(){
 //initialize a GeniusBar

    GeniusBar genius_bar;
    //create some customers
    Customer customer1("Lina", "iPhone");
    cout << customer1.getName() << " has problems with " << customer1.getDevice() << endl;
    Customer customer2("Clay", "iPad");
    cout << customer2.getName() << " has problems with " << customer2.getDevice() << endl;
    Customer customer3("Rory", "iMac");
    cout << customer3.getName() << " has problems with " << customer3.getDevice() << endl;
    Customer customer4("Liam", "macBookPro");
    cout << customer4.getName() << " has problems with " << customer4.getDevice() << endl;
    Customer customer5("Adri", "iPhone");
    cout << customer5.getName() << " has problems with " << customer5.getDevice() << endl;
    Customer customer6("Sky", "macBookAir");
    cout << customer6.getName() << " has problems with " << customer6.getDevice() << endl;


    cout << endl << "add customers to the geinus bar \n";
    cout << genius_bar.addWaitingCustomer(customer1) << endl;  // true (1)
    cout << customer1.getName() << "'s wait time is now " << customer1.getWaitTime() << endl;
    cout << genius_bar.addWaitingCustomer(customer2) << endl;  // true (1)
    cout << customer2.getName() << "'s wait time is now " << customer2.getWaitTime() << endl;
    cout << genius_bar.addWaitingCustomer(customer3) << endl;  // true (1)
    cout << customer3.getName() << "'s wait time is now " << customer3.getWaitTime() << endl;
    cout << genius_bar.addWaitingCustomer(customer4) << endl;  // true (1)
    cout << customer4.getName() << "'s wait time is now " << customer4.getWaitTime() << endl;
    cout << genius_bar.addWaitingCustomer(customer5) << endl;  // true (1)
    cout << customer5.getName() << "'s wait time is now " << customer5.getWaitTime() << endl;
    cout << genius_bar.addWaitingCustomer(customer6) << endl;  // true (0)
    cout << customer6.getName() << "'s wait time is still " << customer6.getWaitTime() << " because there is no more space at the genius bar \n";
    cout << "Sorry Sky please come back later!\n\n";


    cout << endl << "assigning geniuses to assist customers:" << endl;
    cout << genius_bar.assignGeniusToCustomer() << endl;  // true (1)
    cout << genius_bar.assignGeniusToCustomer() << endl;  // true (1)
    cout << genius_bar.assignGeniusToCustomer() << endl;  // true (1)
    cout << genius_bar.assignGeniusToCustomer() << endl;  // true (0)
    cout << "Oops, no more available geniuses, the remaining customers must wait \n\n";


    cout << endl << "release some geniuses from helping customers and make them available again \n";
    cout << genius_bar.releaseGenius() << endl;  // true (1)
    cout << genius_bar.releaseGenius() << endl;  // true (1)
    cout << genius_bar.releaseGenius() << endl;  // true (1)
    cout << genius_bar.releaseGenius() << endl;  // true (0)
    cout << "no more geniuses to be released \n\n";


    cout << "Oops, it's lunch time, our geniuses are going on lunch break, better update the remaining customers' wait time \n";
    cout << genius_bar.updateCustomersWaitTime() << endl; // true (1)

    cout << endl << "Ok, our geniuses are back from lunch, assign more geniuses to help the remaining customers \n";
    cout << genius_bar.assignGeniusToCustomer() << endl;  // true (1)
    cout << genius_bar.assignGeniusToCustomer() << endl;  // true (1)
    cout << genius_bar.assignGeniusToCustomer() << endl;  // true (0)
    cout << "no more customers in the store, all done for today!!! \n\n";

    cout << "do we need to tell any remaining customers that they need to wait unitl tomorrow? \n";
    cout << genius_bar.updateCustomersWaitTime() << endl; // true (0)
    cout << "no we don't, good night!!! \n\n";

    return 0;

}
