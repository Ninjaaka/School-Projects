#include<iostream>
#ifndef CUSTOMER_H_
#define CUSTOMER_H_
using namespace std;

class Customer{
    public:
        Customer();  //default constructor
        Customer(string name, string device = "unknown", int wait_time = 0);   //parameterized constructor

        //return: name_
        string getName();

        //return: defective_device_
        string getDevice();

        //return: wait_time_
        int getWaitTime();

        //post: wait_time_ = new_wait_time
        void updateWaitTime(int new_wait_time);

    private:
        string name_;
        string defective_device_;
        int wait_time_;

}; // end Customer
#endif