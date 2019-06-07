#include "Client.h"

Client::Client()
{
    //ctor
}

Client::Client(string name, string dob, string username, string password, double pay):Person(name, dob, username, password)
{
    //this->pay = pay;
}

string Client::getDetails()
{
    //ostringstream strs;
    //strs << this->pay;
    return Person::getDetails();// + "\nPay: " + strs.str();
}
