#include "Account.h"

Account::Account()
{
	this->balance = 0;
}

Account::Account(double balance)
{
	this->balance = balance;
}

void Account::makeTransaction(double amount)
{
	if (this->getBalance() + balance >= 0)  // The resulting balance is positive
    {
        this->balance += balance;
    }
    else
    {
        cerr << "Not enough money!" << endl;
    }	
}	


