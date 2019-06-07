#include "Admin.h"

Admin::Admin()
{
    //ctor
}

Admin::Admin(string name, string dob, string username, string password, double pay):Person(name, dob, username, password)
{
    this->pay = pay;
}

string Admin::getDetails()
{
    ostringstream strs;
    strs << this->pay;
    return Person::getDetails() + "\nPay: " + strs.str();
}
