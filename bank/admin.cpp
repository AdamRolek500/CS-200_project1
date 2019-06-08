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
    return "Admin\n" + Person::getDetails() + "\nPay: " + strs.str();
}

string Admin::save(){
	ostringstream strs;
    strs << this->pay;
	return (this->getType() + "\n" +
			Person::save() +
			strs.str() + "\n");
} 

string Admin::getType(){
	return "admin";
}

