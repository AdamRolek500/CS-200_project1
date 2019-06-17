#include "Client.h"

Client::Client()
{
    //ctor
}

Client::Client(string name, string dob, string username, string password, int id, double account1 = 0.0, double account2 = 0.0):Person(name, dob, username, password)
{
    this->id = id;
    Account ac1(account1);
    this->accounts[0] = ac1;
    Account ac2(account2);
    this->accounts[1] = ac2;
}

string Client::getDetails()
{
    return "Client\n" + Person::getDetails() + "\nCheckings: " + this->accounts[0].getBalance() + "\nSavings: " + this->accounts[1].getBalance();
}

string Client::save(){
	ostringstream strs;
    strs << this->id;
	return (this->getType() + "\n" +
			Person::save() + 
			strs.str() + "\n" +
			this->accounts[0].getBalance() + "\n" +
			this->accounts[1].getBalance() + "\n");
}

string Client::getType(){
	return "client";
}

