#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <sstream>

using namespace std;

class Account
{
	
	
	public:
		Account();
		Account(double balance);
		
		void makeTransaction(double amount);
		
		string getBalance(){
			ostringstream strs;
    		strs << this->balance;
    		return strs.str();
		}
				
	private:
		double balance;
};


#endif //Account.h
