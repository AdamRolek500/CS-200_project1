#include "Person.h"

Person::Person()
{
    //ctor
}

Person::Person(string name, string dob, string username, string password)
{
    this->name = name;
    this->dob = dob;
    this->username = username;
    this->password = password;
}

string Person::getName()
{
    return this->name;
}

void Person::setName(string name)
{
    this->name = name;
}

string Person::getDOB( )
{
	return this->dob;
}

void Person::setDOB(string dob)
{
	this->dob = dob;	
}

string Person::getUsername()
{
	return this->username;
}

void Person::setUsername(string username)
{
	this->username = username;
}

string Person::getPassword ()
{
	return this->password;
}

void Person::setPassword(string password)
{
	this->password = password;
}

string Person::getDetails()
{
    return ("Name: " + this->name + "\nDate of Birth: " + this->dob +
            "\nUsername: " + this->username + "\nPassword: " + this->password);
}
