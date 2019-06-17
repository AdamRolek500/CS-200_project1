    
#ifndef CLIENT_H
#define CLIENT_H

#include "person.h"
#include <sstream>
#include "account.h"


class Client : public Person
{
public:
    Client();
    Client(string name, string dob, string username, string password, int id, double account1, double account2);

    int getID()
    {
        return id;
    }
    void setID(int id)
    {
        id = id;
    }
	void makeTransaction()
	{
		int option;
		double ammount;
		cout << "(0) Checking: " << this->accounts[0].getBalance() << endl
			 << "(1) Savings: " << this->accounts[1].getBalance() << endl
			 << "Enter an Option > ";
		cin >> option;
		cout << "Enter Deposit Amount > ";
		cin >> ammount;
		this->accounts[option].makeTransaction(ammount);
	}
	virtual string getDetails();
	virtual string getType();
	virtual string save();
    

private:
    int id;
    Account accounts[2];
};

#endif // TELLER_H
