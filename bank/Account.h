#ifndef ACCOUNT_H
#define ACCOUNT_H

using namespace std;

class Account
{
	Account();
	Account(double balance);
	
	
	public:
		void depositFunds(double amount);
		void withdrawFunds(double amount);
				
	private:
		double balance;
};


#endif //Account.h
