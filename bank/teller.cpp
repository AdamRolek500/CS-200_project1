#include "Teller.h"

Teller::Teller()
{
    //ctor
}

Teller::Teller(string name, string dob, string username, string password, double pay):Person(name, dob, username, password)
{
    this->pay = pay;
}

string Teller::getDetails()
{
    ostringstream strs;
    strs << this->pay;
    return Person::getDetails() + "\nPay: " + strs.str();
}
