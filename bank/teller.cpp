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
    return "Teller\n" + Person::getDetails() + "\nPay: " + strs.str();
}

string Teller::save(){
	ostringstream strs;
    strs << this->pay;
	return (this->getType() + "\n" +
			Person::save() +
			strs.str() + "\n");
}

string Teller::getType(){
	return "teller";
}

