
    
#ifndef ADMIN_H
#define ADMIN_H

#include "Person.h"
#include <sstream>


class Admin : public Person
{
public:
    Admin();
    Admin(string name, string dob, string username, string password, double pay);

    double Getpay()
    {
        return pay;
    }
    void Setpay(double val)
    {
        pay = val;
    }

    virtual string getDetails();
    virtual string getType();
    virtual string save();

private:
    double pay;
};

#endif // ADMIN_H
