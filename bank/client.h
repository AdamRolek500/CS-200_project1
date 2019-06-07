    
#ifndef CLIENT_H
#define CLIENT_H

#include "Person.h"
#include <sstream>


class Client : public Person
{
public:
    Client();
    Client(string name, string dob, string username, string password, double pay);

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
		
	}
	string getDetails();
    

private:
    int id;
};

#endif // TELLER_H
