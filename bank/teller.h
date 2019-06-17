    
#ifndef TELLER_H
#define TELLER_H

#include "Person.h"
#include <sstream>


class Teller : public Person
{
public:
    Teller();
    Teller(string name, string dob, string username, string password, double pay);

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

#endif // TELLER_H
