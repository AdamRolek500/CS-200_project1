#include "account.h"

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
	if (this->balance + amount >= 0)  // The resulting balance is positive
    {
        this->balance += amount;
    }
    else
    {
        cerr << "Not enough money!" << endl;
    }	
}	

