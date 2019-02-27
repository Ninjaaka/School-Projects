#include<iostream>
#ifndef GENIUSBAR_H_
#define GENIUSBAR_H_
using namespace std;

class GeniusBar{
public:
    GeniusBar(); //default constructor
    //pre: number_of_customers_ < MAX_NUMBER_OF_CUSTOMERS
    //post: add new_customer to genius_bar_ and increment current_wait_time_ by WAIT_TIME_INCREMENT
    //return: true if number_of_customers_ < MAX_NUMBER_OF_CUSTOMERS, false otherwise
    bool addWaitingCustomer(Customer& new_customer);

    

    //pre: (number_of_customers_ > 0) && (number_of_available_geniuses_ > 0)
    //post: decrement number_of_customers_ and number_of_available_geniuses_
    //return: true if (number_of_customers_ > 0) && (number_of_available_geniuses_ > 0), false otherwise
    bool assignGeniusToCustomer();

    

    //pre: number_of_available_geniuses_ < TOTAL_NUMBER_OF_GENIUSES
    //post: increment number_of_available_geniuses
    //return: true if number_of_available_geniuses_ < TOTAL_NUMBER_OF_GENIUSES, false otherwise
    bool releaseGenius();

    

    //pre: number_of_customers_ > 0
    //post: increment the wait time of each customer on the genius_bar by WAIT_TIME_INCREMENT
    //return: true if number_of_customers_ > 0, false otherwise
    bool updateCustomersWaitTime();

    

    private:
        static const int TOTAL_NUMBER_OF_GENIUSES = 3;
        static const int MAX_NUMBER_OF_CUSTOMERS = 5;
        static const int WAIT_TIME_INCREMENT = 5;
        int current_wait_time_;
        int number_of_available_geniuses_;
        int number_of_customers_;
        Customer genius_bar_[MAX_NUMBER_OF_CUSTOMERS];

}; //end GeniusBar
#endif