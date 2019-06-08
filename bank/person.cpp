#include "Person.h"

string encrypt(string to_encrypt, char key){
    string output = to_encrypt;
    string fin = "";

    for (int i = 0; i < to_encrypt.size(); i++)
        output[i] = to_encrypt[i] ^ key;

    for(int i = 0; i < output.size(); i++){
        fin += std::to_string((int)output[i]) + " ";
    }

    return fin;
}

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

bool Person::login(string username, string password){
	return (this->getUsername() == username && this->getPassword() == password);
}

string Person::getDetails()
{
    return ("Name: " + this->name + "\nDate of Birth: " + this->dob +
            "\nUsername: " + this->username + "\nPassword: " + this->password);
}

string Person::save(){
	return (encrypt(this->name, 'k') + "\n" +
			encrypt(this->dob, 'k') + "\n" +
			encrypt(this->username, 'k') + "\n" +
			encrypt(this->password, 'k') + "\n");
}

string Person::getType(){
	return "person";
}

