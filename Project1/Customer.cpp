//Stanley Su
//Project 1
//CSCI 235
//This cpp file updates customers wait time and displays their information

#include<iostream>
#include "Customer.hpp"
using namespace std;


Customer::Customer(): name_(""), defective_device_("unknown"), wait_time_(0)
{
    
}  //default constructor

Customer::Customer(string name, string device, int wait_time): name_(name), defective_device_(device), wait_time_(wait_time)
{
    
}  //parameterized constructor

//return: name_
string Customer::getName(){
    return name_;
}

//return: defective_device_
string Customer::getDevice(){
    return defective_device_;
}

//return: wait_time_
int Customer::getWaitTime(){
    return wait_time_;
}

//post: wait_time_ = new_wait_time
void Customer::updateWaitTime(int new_wait_time){
     wait_time_ = new_wait_time;
}
