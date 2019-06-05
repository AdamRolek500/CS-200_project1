#ifndef TELLER_H
#define TELLER_H

#include "person.h"
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

private:
    double pay;
};

#endif // TELLER_H
